//
// Created by Jakub Kordel on 17.05.2019
//

#ifndef PACMAN_BLINKY_H
#define PACMAN_BLINKY_H

#include "Ghost.h"

/// Jeden z duszków 
class Blinky : public Ghost {

	void huntMove();

public:
	Blinky ( const sf::Vector2f & vector, std::vector<Node*> & nodesVector, Player * playerPointer, std::vector<Tunnel*> * tunnelsVector );
	///Wykonuje ruch duszka zgodnie z jego taktyką
	void move();	
};


#endif //PACMAN_BLINKY_H
