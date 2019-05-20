//
// Created by Jakub Kordel on 17.05.2019
//

#include "Blinky.h"

Blinky::Blinky ( const sf::Vector2f & vector, std::vector<Node*> & nodesVector, Player * playerPointer, std::vector<Tunnel*> * tunnelsVector ) : Ghost ( vector, nodesVector, playerPointer, tunnelsVector ) {
	setFillColor(sf::Color::Red);
	randomization = 15;
	positionInCage = sf::Vector2f(315.f, 351.f);
	goToCage();
}

void Blinky::move(){
	if ( state == RANDOM ) randomMove();
	else if ( state == HUNT ) huntMoveLikeBlinky();
	else escapeMove(); 
}

