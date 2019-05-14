//
// Created by Jakub Kordel on 11.05.2019 
//

#ifndef PACMAN_NODE_H
#define PACMAN_NODE_H

#include <SFML/Graphics.hpp>

class NodesGenerator;

class Node : public sf::RectangleShape {
	friend class NodesGenerator;
public:
	const bool up;
	const bool down;
	const bool left;
	const bool right;

private:
	
	Node * nodeUp;
	Node * nodeDown;
	Node * nodeLeft;
	Node * nodeRight;

public:
	Node ( sf::Vector2f vector, bool u, bool d, bool l, bool r );
	virtual void visit(){}

	Node * getNodeUp();
	Node * getNodeDown();
	Node * getNodeLeft();
	Node * getNodeRight();
};


#endif //PACMAN_NODE_H
