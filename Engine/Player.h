//
// Created by Jakub Kordel on 11.05.2019
//

#ifndef PACMAN_PLAYER_H
#define PACMAN_PLAYER_H

#include "Node.h"
#include "DynamicObject.h"

class Player : public DynamicObject {
	


public:

	Direction lastWantedDirection;
	Player( const sf::Vector2f & vector );
	void move( std::vector<Node> & nodes ); 
};


#endif //PACMAN_PLAYER_H
