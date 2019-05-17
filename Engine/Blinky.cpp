//
// Created by Jakub Kordel on 17.05.2019
//

#include "Blinky.h"



Blinky::Blinky ( const sf::Vector2f & vector, std::vector<Node*> & nodesVector, Player * playerPointer, std::vector<Tunnel*> * tunnelsVector ) : Ghost ( vector, nodesVector, playerPointer, tunnelsVector ) {
	setFillColor(sf::Color::Green);
	state = HUNT;
	speedValue = 0.17;
}

void Blinky::move(){
	if ( state == RANDOM ) randomMove();
	else if ( state == HUNT ) huntMove();
	else escapeMove(); 
}

void Blinky::huntMove(){
	std::vector<Tunnel*> & tunnel = *tunnels;
	Node * n = isInNode();
	int randNum;
	if ( n ) setPosition( n -> getPosition() );
	int pos = playerPosition();
	randNum = std::rand()%100;
	if ( randNum < 20 ) pos = 8; 
	if ( n && pos != 8){
		if ( n -> getPosition() == tunnel[0] -> getPosition() || n -> getPosition() == tunnel[1] -> getPosition() ) n -> visit();

		switch ( movement ){

			case UP:
			  if ( !n -> left && !n -> right ){
				if ( !n -> up ) changeMovement( DOWN );
			  } 
			  else if ( n -> up && n -> left && n -> right ){
				switch ( pos ){
				  case 0:
				    if ( player ->movement == UP || player ->movement == LEFT ) changeMovement( RIGHT );
				    else if ( player ->movement == NONE ) {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(RIGHT);
				    }
				    break;
				  case 1:
				    break;
				  case 2:
				    if ( player ->movement == UP || player ->movement == RIGHT ) changeMovement( LEFT );
				    else if ( player ->movement == NONE ) {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(LEFT);
				    }
				    break;
				  case 3: case 4:
				    changeMovement(LEFT);
				    break;
				  case 5:
				    if ( player -> movement == LEFT ) changeMovement(RIGHT);
				    else if ( player -> movement == RIGHT ) changeMovement(LEFT);
				    else {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(LEFT);
					else changeMovement(RIGHT);
				    }
				    break;
				  case 6: case 7:
				    changeMovement(RIGHT);
				    break;
				}
			  }
			  else if ( !n -> up && n -> left && n -> right ){
				switch (pos){
				  case 2: case 3: case 4:
				    changeMovement(LEFT);
				    break;
				  case 0: case 6: case 7:
				    changeMovement(RIGHT);
				    break;
				  case 1:
				    if ( player -> movement == RIGHT ) changeMovement(LEFT);
				    else if ( player -> movement == LEFT ) changeMovement(RIGHT);
				    else {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(LEFT);
					else changeMovement(RIGHT);
				    }
				    break;
				  case 5:
				    changeMovement(DOWN);
				    break;
				}
			  }
			  else if ( n -> up ){
				if ( n ->left ){
					switch ( pos ){
					  case 0: case 1: case 7: 
					    break;
					  case 2: case 6:
					    if ( player ->movement == RIGHT || player ->movement == UP ) changeMovement( LEFT );
					    else if ( player ->movement == NONE ) {
						randNum = std::rand()%2;
						if ( randNum ) changeMovement(LEFT);
					    }
					    break;
					  case 3: case 4: case 5:
					    changeMovement(LEFT);
					    break;
					}
				}				
				else {
					switch ( pos ){
					  case 1: case 2: case 3: 
					    break;
					  case 0: case 4:
					    if ( player ->movement == LEFT || player ->movement == UP ) changeMovement( RIGHT );
					    else if ( player ->movement == NONE ) {
						randNum = std::rand()%2;
						if ( randNum ) changeMovement(RIGHT);
					    }
					    break;
					  case 5: case 6: case 7:
					    changeMovement(RIGHT);
					    break;
					}
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
				switch ( pos ){
				  case 6:
				    if ( player ->movement == DOWN || player ->movement == LEFT ) changeMovement( RIGHT );
				    else if ( player ->movement == NONE ) {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(RIGHT);
				    }
				    break;
				  case 5:
				    break;
				  case 4:
				    if ( player ->movement == DOWN || player ->movement == RIGHT ) changeMovement( LEFT );
				    else if ( player ->movement == NONE ) {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(LEFT);
				    }
				    break;
				  case 2: case 3:
				    changeMovement(LEFT);
				    break;
				  case 1:
				    if ( player -> movement == LEFT ) changeMovement(RIGHT);
				    else if ( player -> movement == RIGHT ) changeMovement(LEFT);
				    else {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(LEFT);
					else changeMovement(RIGHT);
				    }
				    break;
				  case 0: case 7:
				    changeMovement(RIGHT);
				    break;
				}
			  }
			  else if ( !n -> down && n -> left && n -> right ){
				switch (pos){
				  case 2: case 3: case 4:
				    changeMovement(LEFT);
				    break;
				  case 0: case 6: case 7:
				    changeMovement(RIGHT);
				    break;
				  case 5:
				    if ( player -> movement == LEFT ) changeMovement(RIGHT);
				    else if ( player -> movement == RIGHT ) changeMovement(LEFT);
				    else {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(LEFT);
					else changeMovement(RIGHT);
				    }
				    break;
				  case 1:
				    changeMovement(UP);
				    break;
				}
			  }
			  else if ( n -> down ){
				if ( n ->left ){
					switch ( pos ){
					  case 5: case 6: case 7: 
					    break;
					  case 0: case 4:
					    if ( player ->movement == RIGHT || player ->movement == DOWN ) changeMovement( LEFT );
					    else if ( player ->movement == NONE ) {
						randNum = std::rand()%2;
						if ( randNum ) changeMovement(LEFT);
					    }
					    break;
					  case 1: case 2: case 3:
					    changeMovement(LEFT);
					    break;
					}
				}				
				else {
					switch ( pos ){
					  case 3: case 4: case 5: 
					    break;
					  case 2: case 6:
					    if ( player ->movement == LEFT || player ->movement == DOWN ) changeMovement( RIGHT );
					    else if ( player ->movement == NONE ) {
						randNum = std::rand()%2;
						if ( randNum ) changeMovement(RIGHT);
					    }
					    break;
					  case 0: case 1: case 7:
					    changeMovement(RIGHT);
					    break;
					}
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
				switch ( pos ){
				  case 2:
				    if ( player ->movement == LEFT || player ->movement == DOWN ) changeMovement( UP );
				    else if ( player ->movement == NONE ) {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(UP);
				    }
				    break;
				  case 3:
				    break;
				  case 4:
				    if ( player ->movement == LEFT || player ->movement == UP ) changeMovement( DOWN );
				    else if ( player ->movement == NONE ) {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(DOWN);
				    }
				    break;
				  case 0: case 1:
				    changeMovement(UP);
				    break;
				  case 7:
				    if ( player -> movement == UP ) changeMovement(DOWN);
				    else if ( player -> movement == DOWN ) changeMovement(UP);
				    else {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(UP);
					else changeMovement(DOWN);
				    }
				    break;
				  case 5: case 6:
				    changeMovement(DOWN);
				    break;
				}
			  }
			  else if ( !n -> left && n -> up && n -> down ){
				switch (pos){
				  case 0: case 1: case 2:
				    changeMovement(UP);
				    break;
				  case 4: case 5: case 6:
				    changeMovement(DOWN);
				    break;
				  case 3:
				    if ( player -> movement == UP ) changeMovement(DOWN);
				    else if ( player -> movement == DOWN ) changeMovement(UP);
				    else {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(UP);
					else changeMovement(DOWN);
				    }
				    break;
				  case 7:
				    changeMovement(RIGHT);
				    break;
				}
			  }
			  else if ( n -> left ){
				if ( n ->up ){
					switch ( pos ){
					  case 3: case 4: case 5: 
					    break;
					  case 2: case 6:
					    if ( player ->movement == DOWN || player ->movement == LEFT ) changeMovement( UP );
					    else if ( player ->movement == NONE ) {
						randNum = std::rand()%2;
						if ( randNum ) changeMovement(UP);
					    }
					    break;
					  case 1: case 0: case 7:
					    changeMovement(UP);
					    break;
					}
				}				
				else {
					switch ( pos ){
					  case 1: case 2: case 3: 
					    break;
					  case 0: case 4:
					    if ( player ->movement == LEFT || player ->movement == UP ) changeMovement( DOWN );
					    else if ( player ->movement == NONE ) {
						randNum = std::rand()%2;
						if ( randNum ) changeMovement(DOWN);
					    }
					    break;
					  case 5: case 6: case 7:
					    changeMovement(DOWN);
					    break;
					}
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
				switch ( pos ){
				  case 0:
				    if ( player ->movement == RIGHT || player ->movement == DOWN ) changeMovement( UP );
				    else if ( player ->movement == NONE ) {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(UP);
				    }
				    break;
				  case 7:
				    break;
				  case 6:
				    if ( player ->movement == RIGHT || player ->movement == UP ) changeMovement( DOWN );
				    else if ( player ->movement == NONE ) {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(DOWN);
				    }
				    break;
				  case 2: case 1:
				    changeMovement(UP);
				    break;
				  case 3:
				    if ( player -> movement == DOWN ) changeMovement(UP);
				    else if ( player -> movement == UP ) changeMovement(DOWN);
				    else {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(UP);
					else changeMovement(DOWN);
				    }
				    break;
				  case 5: case 4:
				    changeMovement(DOWN);
				    break;
				}
			  }
			  else if ( !n -> right && n -> up && n -> down ){
				switch (pos){
				  case 0: case 1: case 2:
				    changeMovement(UP);
				    break;
				  case 4: case 5: case 6:
				    changeMovement(DOWN);
				    break;
				  case 3:
				    if ( player -> movement == DOWN ) changeMovement(UP);
				    else if ( player -> movement == UP ) changeMovement(DOWN);
				    else {
					randNum = std::rand()%2;
					if ( randNum ) changeMovement(UP);
					else changeMovement(DOWN);
				    }
				    break;
				  case 7:
				    changeMovement(LEFT);
				    break;
				}
			  }
			  else if ( n -> right ){
				if ( n ->up ){
					switch ( pos ){
					  case 5: case 6: case 7: 
					    break;
					  case 0: case 4:
					    if ( player ->movement == DOWN || player ->movement == RIGHT ) changeMovement( UP );
					    else if ( player ->movement == NONE ) {
						randNum = std::rand()%2;
						if ( randNum ) changeMovement(UP);
					    }
					    break;
					  case 1: case 2: case 3:
					    changeMovement(UP);
					    break;
					}
				}				
				else {
					switch ( pos ){
					  case 0: case 1: case 7: 
					    break;
					  case 2: case 6:
					    if ( player ->movement == RIGHT || player ->movement == UP ) changeMovement( DOWN );
					    else if ( player ->movement == NONE ) {
						randNum = std::rand()%2;
						if ( randNum ) changeMovement(DOWN);
					    }
					    break;
					  case 3: case 4: case 5:
					    changeMovement(DOWN);
					    break;
					}
				}
			  }
			  else {
				if ( n -> up ) changeMovement(UP);
				else changeMovement(DOWN);
			  }
			  break;
		}
	} else if ( n ) randomMove();
	if ( pos != 8)
		DynamicObject::move();
}
