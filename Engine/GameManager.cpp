//
// Created by Jakub Kordel on 19.05.2019
//

#include "GameManager.h"

GameManager::GameManager( ){
	isStartWanted = false;
	state = BEFOREROUND;
	level = 0;
	lifes = 3;
	points = 0;
	foodNum = 0;
	inCageTime = 180;
	huntTime = 2700;
	randomTime = 900;

	NodesGenerator generator( nodes, smallFoods, bigFoods, specialFoods, tunnels, sf::Vector2f(15.f,15.f));
	DynamicObject * dynamicObject;
	dynamicObject = player = new Player(sf::Vector2f(9.f, 9.f), nodes );
	dynamicObjects.push_back(dynamicObject);

	dynamicObject = ghost = blinky = new Blinky(sf::Vector2f(9.f, 9.f), nodes, player, &tunnels );
	dynamicObjects.push_back(dynamicObject);
	ghosts.push_back(ghost);

	dynamicObject = ghost = pinky = new Pinky(sf::Vector2f(9.f, 9.f), nodes, player, &tunnels );
	dynamicObjects.push_back(dynamicObject);
	ghosts.push_back(ghost);

	dynamicObject = ghost = clyde = new Clyde(sf::Vector2f(9.f, 9.f), nodes, player, &tunnels );
	dynamicObjects.push_back(dynamicObject);
	ghosts.push_back(ghost);	

	dynamicObject = ghost = inky = new Inky(sf::Vector2f(9.f, 9.f), nodes, player, &tunnels );
	dynamicObjects.push_back(dynamicObject);
	ghosts.push_back(ghost);

	tunnels[0] -> objects = dynamicObjects;
	tunnels[1] -> objects = dynamicObjects;

	for ( SmallFood * sf : smallFoods ){
		++foodNum;
		sf -> game = this;	
	}
	
	for ( BigFood * bf : bigFoods ){
		++foodNum;
		bf -> game = this;
	}
	foodLeft = foodNum;
}


GameManager::~GameManager(){
	for ( Node * node : nodes )
		delete node;

	for ( DynamicObject * object : dynamicObjects)
		delete object;
}

Ghost * GameManager::isPlayerGhostCollision(){
	for ( Ghost * g : ghosts ){
		if ( std::abs( player -> getPosition().x - g -> getPosition().x) < 4.5 && std::abs( player -> getPosition().y - g -> getPosition().y ) < 4.5 ) return g;
	}
	return nullptr;
}

void GameManager::action(){
	++stateTimer;
	if ( state != BEFOREROUND ) {
		for ( Ghost * g : ghosts ){
			if ( g -> isInCage ) {
				++g -> timeInCage;
				if ( g ->timeInCage == inCageTime ) g ->respawn();
			}
		}
	}
	
	if ( state == BEFOREROUND ){
		if ( isStartWanted ) startRound();
	} else if ( state == RANDOM && !isPlayerGhostCollision() ){
		moveGhosts();
		player -> move();
		if ( stateTimer == randomTime ) startHunt();
	}else if ( state == HUNT && !isPlayerGhostCollision()) {
		moveGhosts();
		player -> move();
		if ( stateTimer == huntTime ) startRandom();
	} else if ( state == ESCAPE ) {



	} else if ( state == ENDING ){


	} else if ( state == LOST ){


	}
}

void GameManager::startRound(){
	++level;
	startRandom();
	inky -> timeInCage = inCageTime - 1;
	clyde -> timeInCage = 0.75 * inCageTime - 1;
	pinky ->timeInCage = 0.5*inCageTime - 1;
	blinky ->timeInCage = 0.25*inCageTime - 1;
}


void GameManager::startHunt(){
	state = HUNT;
	for ( Ghost * g : ghosts ){
		g -> state = Ghost::HUNT;
	}
	stateTimer = 0;
}

void GameManager::startRandom(){
	state = RANDOM;
	for ( Ghost * g : ghosts ){
		g -> state = Ghost::RANDOM;
	}
	stateTimer = 0;
}

void GameManager::startEscape(){
	state = ESCAPE;
	for ( Ghost * g : ghosts ){
		g -> state = Ghost::ESCAPE;
	}
	stateTimer = 0;
}

void GameManager::startEnding(){
	state = ENDING;
	for ( Ghost * g : ghosts ){
		g -> state = Ghost::HUNT;
	}
	blinky -> speedValue = 2.09;
	stateTimer = 0;
}

void GameManager::moveGhosts(){
	for ( Ghost * g : ghosts )
		if ( !g -> isInCage ) g ->move();
}


   
