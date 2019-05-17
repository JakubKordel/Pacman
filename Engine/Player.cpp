//
// Created by Jakub Kordel on 11.05.2019
//

#include "Player.h"

Player::Player( const sf::Vector2f & vector, std::vector<Node*> & nodesVector ) : DynamicObject( vector, nodesVector ) {
	setFillColor(sf::Color::Yellow);
	lastWantedDirection = NONE;
	spawnPoint = sf::Vector2f(39.f,39.f);
	respawn();
}


void Player::move(){
	Node * n = isInNode();
	if ( n ){
		setPosition( n -> getPosition() );
		n -> visit();
		bool flag = false;
		switch ( lastWantedDirection ){
			case UP:
				if ( n -> up ){ changeMovement( UP );
					flag = true;
				}
				break;
			case DOWN:
				if ( n -> down ){ changeMovement( DOWN );
					flag = true;
				}
				break;
			case LEFT:
				if ( n -> left ){ changeMovement( LEFT );
					flag = true;
				}
				break;
			 case RIGHT:
				if ( n -> right ){ changeMovement( RIGHT );
					flag = true;
				}
				break;
		}
		if ( flag == false ) {
			switch ( movement ){
			  	case UP:
					if ( !n ->up ) changeMovement( NONE );
					break;
			 	case DOWN:
					if ( !n ->down ) changeMovement( NONE );
					break;
			  	case LEFT:
					if ( !n ->left ) changeMovement( NONE );
					break;
			  	case RIGHT:
					if ( !n ->right ) changeMovement( NONE );
					break;
				}	
		}
	} 
	else {
		switch ( lastWantedDirection ){
			case UP:
				if ( movement == DOWN ) changeMovement( UP );
				break;
			case DOWN:
				if ( movement == UP) changeMovement( DOWN );
				break;
		  	case LEFT:
				if ( movement == RIGHT ) changeMovement( LEFT );
				break;
			case RIGHT:
				if ( movement == LEFT ) changeMovement( RIGHT );
				break;
		}
	}
	DynamicObject::move();
}
