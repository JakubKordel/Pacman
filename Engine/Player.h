//
// Created by Jakub Kordel on 11.05.2019
//

#ifndef PACMAN_PLAYER_H
#define PACMAN_PLAYER_H

#include "Node.h"
#include "DynamicObject.h"

class Ghost;
/// reprezentuje gracza poruszającego się po mapie
class Player : public DynamicObject {

friend class Ghost;

public:

	Player( const sf::Vector2f & vector, std::vector<Node*> & nodesVector );
	/// Wykonuje ruch gracza
	/**
	Wykonuje ruch gracza w kierunku określonym przez dziedziczony atrybut lastWantedDirection.
	Jeśli ruch jest niemożliwy, gracz nie wykonuje ruchu.
	*/ 
	void move( ); 
};


#endif //PACMAN_PLAYER_H
