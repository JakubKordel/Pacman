//
// Created by Jakub Kordel on 13.05.2019
//

#include "SmallFood.h"

SmallFood::SmallFood( sf::Vector2f vector, bool u, bool d, bool l, bool r ) : Food( vector, u, d, l, r )  {
	setFillColor( sf::Color::White );
}

void SmallFood::visit(){
	if ( !isEaten ){
		setFillColor( sf::Color::Black );
		isEaten = true;
	}
}
