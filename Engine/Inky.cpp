//
// Created by Jakub Kordel on 18.05.2019
//

#include "Inky.h"

Inky::Inky ( const sf::Vector2f & vector, std::vector<Node*> & nodesVector, Player * playerPointer, std::vector<Tunnel*> * tunnelsVector ) : Ghost ( vector, nodesVector, playerPointer, tunnelsVector ) {
	setFillColor(sf::Color::Blue);
	randomization = 45;
	speedValue = 2.0;
	positionInCage = sf::Vector2f(291.f, 351.f);
	goToCage();
}

void Inky::move(){
	if ( state == RANDOM ) randomMove();
	else if ( state == HUNT ) huntMoveLikeBlinky();
	else escapeMove(); 
}

