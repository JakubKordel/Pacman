//
// Created by Jakub Kordel on 13.05.2019
//

#include "Tunnel.h"

Tunnel::Tunnel( sf::Vector2f vector, bool u, bool d, bool l, bool r ) : Node( vector, u, d, l, r )  {
	setFillColor( sf::Color::Black );
}

void Tunnel::visit(){
	for ( DynamicObject * object : objects ){
		if ( object ->getPosition() == getPosition() ){
			if ( direction == DynamicObject::LEFT && object ->lastWantedDirection != DynamicObject::RIGHT && object ->movement == DynamicObject::LEFT ){
				object ->setPosition( getNodeLeft() -> getPosition() );
				object ->lastNode = getNodeLeft();
			}
			else if ( direction == DynamicObject::RIGHT && object ->lastWantedDirection != DynamicObject::LEFT && object ->movement == DynamicObject::RIGHT){
				object ->setPosition( getNodeRight() -> getPosition() );
				object ->lastNode = getNodeRight();
			}
			
		}
	}
}
