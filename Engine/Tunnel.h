//
// Created by Jakub Kordel on 13.05.2019
//

#ifndef PACMAN_TUNNEL_H
#define PACMAN_TUNNEL_H

#include "Node.h"
#include <SFML/Graphics.hpp>
#include "DynamicObject.h"

class Tunnel : public Node {

public:
	Tunnel( sf::Vector2f vector, bool u, bool d, bool l, bool r);
	
	std::vector<DynamicObject*> objects;

	DynamicObject::Direction direction ;
	void visit();
};


#endif //PACMAN_TUNNEL_H
