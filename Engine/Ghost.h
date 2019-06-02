//
// Created by Jakub Kordel on 16.05.2019
//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H

#include "Node.h"
#include "DynamicObject.h"
#include "Player.h"
#include "cstdlib"
#include "Tunnel.h"

class Ghost : public DynamicObject {

public:

	enum State { RANDOM, HUNT, ESCAPE };

	State state;

	Player * player;
	std::vector<Tunnel*> * tunnels;
	bool isInCage;
	size_t timeInCage;

	int randomization; // < 100
	sf::Vector2f positionInCage;
	Ghost ( const sf::Vector2f & vector, std::vector<Node*> & nodesVector, Player * playerPointer, std::vector<Tunnel*> * tunnels );
	virtual void move ( ){}
	void reverseMovement();
	void respawn();
	void randomMove();
	void huntMoveLikeBlinky();
	void huntMoveLikePinky();
	void escapeMove();
	void goToCage();
	int playerPosition(); //   2 1 0
			      //   3 G 7  G - ghost 
			      //   4 5 6
};


#endif //PACMAN_GHOST_H
