//
// Created by Jakub Kordel on 11.05.2019
//

#include "DynamicObject.h"

const int Distance = 23; 

float mod ( const float & x ){
	if ( x < 0 ) return -x;
	else return x;
}

DynamicObject::DynamicObject( const sf::Vector2f & vector, std::vector<Node*> & nodesVector ) : RectangleShape ( vector ), nodes(nodesVector) {
	setOrigin( sf::Vector2f( vector.x/2, vector.y/2 ) );
	movement = NONE;
	lastNode = nullptr;
	speedValue = 2;
	speed = sf::Vector2f(0.f, 0.f);
}
	
void DynamicObject::move(){
	sf::RectangleShape::move( speed );			
}

void DynamicObject::changeMovement( const Direction & direction ){
	movement = direction;
	if ( movement == UP ) speed = sf::Vector2f(0.f, -speedValue );
	else if ( movement == DOWN ) speed = sf::Vector2f(0.f, speedValue);
	else if ( movement == LEFT ) speed = sf::Vector2f(-speedValue, 0.f);
	else if ( movement == RIGHT ) speed = sf::Vector2f(speedValue, 0.f);
	else speed = sf::Vector2f( 0.f, 0.f );	
}

Node * DynamicObject::isInNode(){
	float catchValue = 0.51*speedValue;
	if ( movement == NONE && lastNode ) return lastNode;
	else if ( lastNode ){
		if ( mod ( getPosition().x - lastNode -> getPosition().x ) < catchValue &&  mod (  getPosition().y - lastNode -> getPosition().y ) < catchValue ) return lastNode;
		switch ( movement ){
		 	case UP:
			  if ( lastNode -> up && mod ( getPosition().y - lastNode ->getNodeUp()-> getPosition().y ) < catchValue ) return lastNode = lastNode ->getNodeUp();
			  break;
		 	case DOWN:
			  if ( lastNode -> down && mod ( getPosition().y - lastNode ->getNodeDown()-> getPosition().y ) < catchValue ) return lastNode = lastNode ->getNodeDown();
			  break;
		 	case LEFT:
			  if ( lastNode -> left && mod ( getPosition().x - lastNode ->getNodeLeft()-> getPosition().x ) < catchValue ) return lastNode = lastNode ->getNodeLeft();
			  break;
		 	case RIGHT:
			  if (  lastNode -> right && mod ( getPosition().x - lastNode ->getNodeRight()-> getPosition().x ) < catchValue ) return lastNode = lastNode ->getNodeRight();
			  break;
			case NONE:
			  break;
		}
		return nullptr;
	}

	float y = nodes[0] -> getPosition().y;
	float x = nodes[0] -> getPosition().x;
	int counter = 0;
	while ( counter < 29 ){
		if ( mod ( y - getPosition().y ) < catchValue ) break;
		y = y + Distance + 1;
		++counter;
	}	
	if ( counter < 29 ){
		counter = 0;
		while ( counter < 26 ){
			if ( mod ( x - getPosition().x ) < catchValue ) break;
			x = x + Distance + 1;
			++counter;	
		}	
		if ( counter < 26 )  {
			for ( unsigned int i = 0; i < nodes.size() ; ++i ){
				if ( mod( getPosition().x - nodes[i] ->getPosition().x)  < catchValue && mod( getPosition().y - nodes[i] ->getPosition().y )  < catchValue  )
					return lastNode = nodes[i];
			}
		}
	}
	return nullptr;
}

void DynamicObject::respawn(){
	setPosition( spawnPoint );
}
