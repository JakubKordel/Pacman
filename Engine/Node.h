//
// Created by Jakub Kordel on 11.05.2019 
//

#ifndef PACMAN_NODE_H
#define PACMAN_NODE_H

#include <SFML/Graphics.hpp>

class Node : public sf::RectangleShape {
public:
	const bool up;
	const bool down;
	const bool left;
	const bool right;

	Node ( sf::Vector2f vector, bool u, bool d, bool l, bool r );

	virtual void visit(){}
};


#endif //PACMAN_NODE_H
