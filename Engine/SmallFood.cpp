//
// Created by Jakub Kordel on 13.05.2019
//

#include "SmallFood.h"
#include "GameManager.h"

SmallFood::SmallFood( sf::Vector2f vector, bool u, bool d, bool l, bool r ) : Food( vector, u, d, l, r )  {
	setFillColor( sf::Color::White );
}

void SmallFood::visit(){
	if ( !isEaten ){
		--game ->foodLeft;
		game ->points += 10;
		setFillColor( sf::Color::Black );
		isEaten = true;
	}
}

void SmallFood::reset(){
	setFillColor( sf::Color::White );
	isEaten = false;
}
