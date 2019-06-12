//
// Created by Jakub Kordel on 18.05.2019
//

#ifndef PACMAN_CLYDE_H
#define PACMAN_CLYDE_H

#include "Ghost.h"
#include <cmath>

/// Jeden z duszków 
class Clyde : public Ghost {

	void huntMove();

public:
	Clyde ( const sf::Vector2f & vector, std::vector<Node*> & nodesVector, Player * playerPointer, std::vector<Tunnel*> * tunnelsVector );
	///Wykonuje ruch duszka zgodnie z jego taktyką
	void move();	
};


#endif //PACMAN_CLYDE_H
