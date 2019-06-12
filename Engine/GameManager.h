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

/// Klasa odpowiadająca za sterowanie rozgrywką 
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
	/// Sprawdza czy wystąpiła kolizja gracza z duszkiem
	/**
	Jeśli kolizja wystąpiła, zwracany jest wskaźnik na duszka z którym wystąpiła kolizja. Jeśli nie, zwracany jest wskaźnik nullptr.
	*/ 
	Ghost * isPlayerGhostCollision();
	///Metoda wykonuje kolejną 'klatkę' gry
	void action();
	///Metoda tworzy nową rundę gry. 
	void startRound();
	///Włącza losowy tryb poruszania się duszków
	void startRandom();
	///Włącza tryb gonitwy
	void startHunt();
	///Włącza tryb ucieczki duszków
	void startEscape();
	///Włącza tryb końcowy 
	/**
	Jest to tryb włączany gdy na planszy zostanie mała ilość jedzenia
	*/
	void startEnding();
	///Metoda powoduje wykonanie swoich ruchów przez duszki
	void moveGhosts();
	///Metoda ustawia gracza w pozycje startową, duszki przenosi do klatki.  
	void resetPositions();
	/// Ustawia jedzenie na całej mapie jako niezjedzone 
	void resetFoods();
	/// Resetuje cała rozgrywke ( Po porażce gracza )
	void reset();
};


#endif //PACMAN_GAMEMANAGER_H
