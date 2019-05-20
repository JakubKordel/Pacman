//
// Created by Jakub Kordel on 18.05.2019
//

#include "Clyde.h"

Clyde::Clyde ( const sf::Vector2f & vector, std::vector<Node*> & nodesVector, Player * playerPointer, std::vector<Tunnel*> * tunnelsVector ) : Ghost ( vector, nodesVector, playerPointer, tunnelsVector ) {
	setFillColor(sf::Color(244, 137, 66));
	randomization = 0;
	speedValue = 1.9;
	positionInCage = sf::Vector2f(387.f, 351.f);
	goToCage();
}

void Clyde::move(){
	if ( state == RANDOM  ) randomMove();
	else if ( state == HUNT && pow( pow( getPosition().x - player ->getPosition().x, 2) + pow( getPosition().y - player ->getPosition().y, 2 ), 0.5 ) > 130 ) huntMoveLikeBlinky();
	else escapeMove(); 
}

