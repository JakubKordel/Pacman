//
// Created by Jakub Kordel on 18.05.2019
//

#ifndef PACMAN_INKY_H
#define PACMAN_INKY_H

#include "Ghost.h"

/// Jeden z duszków 
class Inky : public Ghost {

	void huntMove();

public:
	Inky ( const sf::Vector2f & vector, std::vector<Node*> & nodesVector, Player * playerPointer, std::vector<Tunnel*> * tunnelsVector );
	///Wykonuje ruch duszka zgodnie z jego taktyką
	void move();	
};


#endif //PACMAN_INKY_H
