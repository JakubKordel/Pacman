//
// Created by Jakub Kordel on 11.05.2019
//

#ifndef PACMAN_DYNAMICOBJECT_H
#define PACMAN_DYNAMICOBJECT_H 

#include <SFML/Graphics.hpp>

class DynamicObject : public sf::RectangleShape {
public:
	enum Direction { UP, DOWN, LEFT, RIGHT, NONE };

protected:
	Direction movement; 
	sf::Vector2f speed;
	float speedValue; // > 0 
 	
public:
	DynamicObject( const sf::Vector2f & vector );
	void move(); 	
	void changeMovement( const Direction & direction );
};


#endif //PACMAN_DYNAMICOBJECT_H
