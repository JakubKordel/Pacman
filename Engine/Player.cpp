//
// Created by Jakub Kordel on 11.05.2019
//

#include "Player.h"

Player::Player( const sf::Vector2f & vector ) : DynamicObject( vector ) {
	setFillColor(sf::Color::Yellow);
	lastWantedDirection = NONE;
}


void Player::move( std::vector<Node*> & nodes ){
	for ( int i = 0; i < nodes.size() ; ++i ){
		Node * n = nodes[i];
		float catchValue = 0.51*speedValue;
		if ( n ->getPosition().x - getPosition().x > -catchValue && n ->getPosition().x - getPosition().x < catchValue && n ->getPosition().y - getPosition().y > -catchValue && n ->getPosition().y - getPosition().y < catchValue ){
			//if ( !n.isEaten ){
			//	n.isEaten = true;
			//	n.setFillColor( sf::Color::Blue);	
			//}
			setPosition( n -> getPosition() );
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
			break;
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
	}
	DynamicObject::move();
}
