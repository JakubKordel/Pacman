//
// Created by Jakub Kordel on 19.05.2019
//

#ifndef PACMAN_GAMEMANAGER_H
#define PACMAN_GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include "Node.h"
#include "DynamicObject.h"
#include "Player.h"
#include "NodesGenerator.h"
#include "SmallFood.h"
#include "BigFood.h"
#include "SpecialFood.h"
#include "Tunnel.h"
#include "Ghost.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Clyde.h"
#include "Inky.h"
#include <iostream>
#include <ctime>
#include <cmath>

class GameManager{

public:
	enum GameState { BEFOREROUND, RANDOM, HUNT, ESCAPE, ENDING, LOST, WON, LIFELOST };
	unsigned int level;
	size_t points;
	unsigned int lifes;
	unsigned int foodNum;
	unsigned int foodLeft;
	GameState state; 

	std::vector<Node*> nodes;
	std::vector<SmallFood*> smallFoods;
	std::vector<BigFood*> bigFoods;
	std::vector<SpecialFood*> specialFoods;
	std::vector<Tunnel*> tunnels;
	std::vector<DynamicObject*> dynamicObjects;
	std::vector<Ghost*> ghosts;	

	Player * player;
	Ghost * ghost;
	Blinky * blinky;
	Inky * inky;
	Pinky * pinky;
	Clyde * clyde;

	bool isStartWanted;

	size_t stateTimer;

	size_t inCageTime;
	size_t randomTime;
	size_t huntTime;
	size_t escapeTime;

	GameManager();
	~GameManager();

	Ghost * isPlayerGhostCollision();
	void action();
	void startRound();
	void startRandom();
	void startHunt();
	void startEscape();
	void startEnding();
	void moveGhosts();
	void resetPositions();
	void resetFoods();
};


#endif //PACMAN_GAMEMANAGER_H
