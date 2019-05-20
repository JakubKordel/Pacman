//
// Created by Jakub Kordel on 11.05.2019
//

#ifndef PACMAN_PLAYER_H
#define PACMAN_PLAYER_H

#include "Node.h"
#include "DynamicObject.h"

class Ghost;

class Player : public DynamicObject {

friend class Ghost;

public:

	Direction lastWantedDirection;
	Player( const sf::Vector2f & vector, std::vector<Node*> & nodesVector );
	void move( ); 
};


#endif //PACMAN_PLAYER_H
