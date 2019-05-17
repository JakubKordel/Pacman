//
// Created by Jakub Kordel on 16.05.2019
//

#include "Ghost.h"

Ghost::Ghost ( const sf::Vector2f & vector, std::vector<Node*> & nodesVector, Player * playerPointer, std::vector<Tunnel*> * tunnelsVector ) : DynamicObject(vector, nodesVector) { 
	setFillColor(sf::Color::Red);
	player = playerPointer;
	tunnels = tunnelsVector;
	speedValue = 0.15;
}

void Ghost::goToCage(){
	setPosition( positionInCage );
}

void Ghost::randomMove(){
	std::vector<Tunnel*> & tunnel = *tunnels;
	Node * n = isInNode();
	int randNum;
	if ( n ){
		setPosition( n -> getPosition() );
		if ( n -> getPosition() == tunnel[0] -> getPosition() || n -> getPosition() == tunnel[1] -> getPosition() ) n -> visit();
		switch ( movement ){

			case UP:
			  if ( !n -> left && !n -> right ){
				if ( !n -> up ) changeMovement( DOWN );
			  } 
			  else if ( n -> up && n -> left && n -> right ){
				randNum = std::rand()%3;
				switch (randNum){
				  case 0:
				    changeMovement(LEFT);
				    break;
				  case 1:
				    changeMovement(RIGHT);
				    break;
				}
			  }
			  else if ( !n -> up && n -> left && n -> right ){
				randNum = std::rand()%3;
				switch (randNum){
				  case 0:
				    changeMovement(DOWN);
				    break;
				  case 1:
				    changeMovement(LEFT);
				    break;
				  case 2:
				    changeMovement(RIGHT);
				    break;
				}
			  }
			  else if ( n -> up ){
				randNum = std::rand()%2;
				if ( randNum ){
					if ( n -> left ) changeMovement( LEFT );
					else changeMovement( RIGHT );
				}
			  }
			  else {
				if ( n -> left ) changeMovement(LEFT);
				else changeMovement(RIGHT);
			  }
			  break;

			case DOWN:
			  if ( !n -> left && !n -> right ){
				if ( !n -> down ) changeMovement( UP );
			  } 
			  else if ( n -> down && n -> left && n -> right ){
				randNum = std::rand()%3;
				switch (randNum){
				  case 0:
				    changeMovement(LEFT);
				    break;
				  case 1:
				    changeMovement(RIGHT);
				    break;
				}
			  }
			  else if ( !n -> down && n -> left && n -> right ){
				randNum = std::rand()%3;
				switch (randNum){
				  case 0:
				    changeMovement(UP);
				    break;
				  case 1:
				    changeMovement(LEFT);
				    break;
				  case 2:
				    changeMovement(RIGHT);
				    break;
				}
			  }
			  else if ( n -> down ){
				randNum = std::rand()%2;
				if ( randNum ){
					if ( n -> left ) changeMovement( LEFT );
					else changeMovement( RIGHT );
				}
			  }
			  else {
				if ( n -> left ) changeMovement(LEFT);
				else changeMovement(RIGHT);
			  }
			  break;
			
			case LEFT:
			  if ( !n -> up && !n -> down ){
				if ( !n -> left ) changeMovement( RIGHT );
			  } 
			  else if ( n -> left && n -> up && n -> down ){
				randNum = std::rand()%3;
				switch (randNum){
				  case 0:
				    changeMovement(UP);
				    break;
				  case 1:
				    changeMovement(DOWN);
				    break;
				}
			  }
			  else if ( !n -> left && n -> up && n -> down ){
				randNum = std::rand()%3;
				switch (randNum){
				  case 0:
				    changeMovement(RIGHT);
				    break;
				  case 1:
				    changeMovement(UP);
				    break;
				  case 2:
				    changeMovement(DOWN);
				    break;
				}
			  }
			  else if ( n -> left ){
				randNum = std::rand()%2;
				if ( randNum ){
					if ( n -> up ) changeMovement( UP );
					else changeMovement( DOWN );
				}
			  }
			  else {
				if ( n -> up ) changeMovement(UP);
				else changeMovement(DOWN);
			  }
			  break;

			case RIGHT:
			  if ( !n -> up && !n -> down ){
				if ( !n -> right ) changeMovement( LEFT );
			  } 
			  else if ( n -> right && n -> up && n -> down ){
				randNum = std::rand()%3;
				switch (randNum){
				  case 0:
				    changeMovement(UP);
				    break;
				  case 1:
				    changeMovement(DOWN);
				    break;
				}
			  }
			  else if ( !n -> right && n -> up && n -> down ){
				randNum = std::rand()%3;
				switch (randNum){
				  case 0:
				    changeMovement(LEFT);
				    break;
				  case 1:
				    changeMovement(DOWN);
				    break;
				  case 2:
				    changeMovement(UP);
				    break;
				}
			  }
			  else if ( n -> right ){
				randNum = std::rand()%2;
				if ( randNum ){
					if ( n -> up ) changeMovement( UP );
					else changeMovement( DOWN );
				}
			  }
			  else {
				if ( n -> up ) changeMovement(UP);
				else changeMovement(DOWN);
			  }
			  break;

			case NONE:
			  changeMovement(RIGHT);
			  break;
		}
	} 
	DynamicObject::move();
}

void Ghost::escapeMove(){

	//TODO//

}

int Ghost::playerPosition(){
	if ( player -> getPosition().y < getPosition().y ){
		if ( player -> getPosition().x < getPosition().x ) return 2;
		else if ( player -> getPosition().x > getPosition().x ) return 0;
		else return 1;
	}
	else if ( player -> getPosition().y == getPosition().y ){
		if ( player -> getPosition().x < getPosition().x ) return 3;
		else if ( player -> getPosition().x > getPosition().x ) return 7;
		else return 8;
	}
	else {
		if ( player -> getPosition().x < getPosition().x ) return 4;
		else if ( player -> getPosition().x > getPosition().x ) return 6;
		else return 5;
	}
}


