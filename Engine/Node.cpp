//
// Created by Jakub Kordel on 11.05.2019
//

#include "Node.h"

Node::Node ( sf::Vector2f vector, bool u, bool d, bool l, bool r) : RectangleShape( sf::Vector2f(3, 3) ) , up(u), down(d), left(l), right(r) {
	setOrigin(sf::Vector2f(2,2) );
	setPosition( vector );
	setFillColor( sf::Color::White );
}

Node * Node::getNodeUp(){
	return nodeUp;
}

Node * Node::getNodeDown(){
	return nodeDown;
}

Node * Node::getNodeLeft(){
	return nodeLeft;
}

Node * Node::getNodeRight(){
	return nodeRight;
}
