//
// Created by Jakub Kordel on 18.05.2019
//

#ifndef PACMAN_CLYDE_H
#define PACMAN_CLYDE_H

#include "Ghost.h"
#include <cmath>

class Clyde : public Ghost {

	void huntMove();

public:
	Clyde ( const sf::Vector2f & vector, std::vector<Node*> & nodesVector, Player * playerPointer, std::vector<Tunnel*> * tunnelsVector );
	void move();	
};


#endif //PACMAN_CLYDE_H
