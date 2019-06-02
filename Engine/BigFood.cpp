//
// Created by Jakub Kordel on 13.05.2019
//

#include "BigFood.h"
#include "GameManager.h"

BigFood::BigFood( sf::Vector2f vector, bool u, bool d, bool l, bool r ) : Food( vector, u, d, l, r )  {
	setSize( sf::Vector2f( 7,7 ));
	setOrigin( sf::Vector2f( 4,4 ));
	setFillColor(  sf::Color(223, 167, 29) );
}

void BigFood::visit(){
	if ( !isEaten ){
		setFillColor( sf::Color::Black );
		isEaten = true;
		game -> points += 30;
		--game ->foodLeft;
		game -> startEscape();
	}
}

void BigFood::reset(){
	setFillColor( sf::Color(223, 167, 29) );
	isEaten = false;
}
