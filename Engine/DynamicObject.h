//
// Created by Jakub Kordel on 11.05.2019
//

#ifndef PACMAN_DYNAMICOBJECT_H
#define PACMAN_DYNAMICOBJECT_H 

#include <SFML/Graphics.hpp>

#include "Node.h"

class Tunnel;
class GameManager;

class DynamicObject : public sf::RectangleShape {

friend class Tunnel;
friend class GameManager;

public:
	enum Direction { UP, DOWN, LEFT, RIGHT, NONE };

protected:
	std::vector<Node*> & nodes;
	Direction movement; 
	float speedValue; // > 0 
	sf::Vector2f speed;
 	Node * isInNode();
	Node * lastNode;
	sf::Vector2f spawnPoint;
	DynamicObject( const sf::Vector2f & vector, std::vector<Node*> & nodesVector );
	void move(); 	
	void changeMovement( const Direction & direction );
public:
	void respawn();
	Direction lastWantedDirection;
};


#endif //PACMAN_DYNAMICOBJECT_H
