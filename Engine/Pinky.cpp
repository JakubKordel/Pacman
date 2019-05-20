//
// Created by Jakub Kordel on 17.05.2019
//

#include "Pinky.h"

Pinky::Pinky ( const sf::Vector2f & vector, std::vector<Node*> & nodesVector, Player * playerPointer, std::vector<Tunnel*> * tunnelsVector ) : Ghost ( vector, nodesVector, playerPointer, tunnelsVector ) {
	setFillColor(sf::Color(234,137,154));
	randomization = 10;
	speedValue = 2.0;
	positionInCage = sf::Vector2f(363.f, 351.f);
	goToCage();
}

void Pinky::move(){
	if ( state == RANDOM ) randomMove();
	else if ( state == HUNT ) huntMoveLikePinky();
	else escapeMove(); 
}


