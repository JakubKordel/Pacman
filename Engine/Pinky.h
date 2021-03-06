//
// Created by Jakub Kordel on 17.05.2019
//

#ifndef PACMAN_PINKY_H
#define PACMAN_PINKY_H

#include "Ghost.h"

/// Jeden z duszków 
class Pinky : public Ghost {

	void huntMove();

public:
	Pinky ( const sf::Vector2f & vector, std::vector<Node*> & nodesVector, Player * playerPointer, std::vector<Tunnel*> * tunnelsVector );
	///Wykonuje ruch duszka zgodnie z jego taktyką
	void move();	
};


#endif //PACMAN_PINKY_H
