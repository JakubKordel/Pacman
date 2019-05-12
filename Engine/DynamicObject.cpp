//
// Created by Jakub Kordel on 11.05.2019
//

#include "DynamicObject.h"

DynamicObject::DynamicObject( const sf::Vector2f & vector ) : RectangleShape ( vector ) {
	setOrigin( sf::Vector2f( vector.x/2, vector.y/2 ) );
	movement = NONE;
	speedValue = 0.1;
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
