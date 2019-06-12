//
// Created by Jakub Kordel on 13.05.2019
//

#ifndef PACMAN_SMALLFOOD_H
#define PACMAN_SMALLFOOD_H

#include "Food.h"
#include <SFML/Graphics.hpp>

///Reprezentuje mały obiekt do zjedzenia przez gracza
class SmallFood : public Food {

public:
	SmallFood( sf::Vector2f vector, bool u, bool d, bool l, bool r );
	/**
	Ustawia obiekt w tryb zjedzony i dodaje 10 do licznika punków gracza.
	*/
	void visit();
	/// Ustawia obiekt jako niezjedzony
	void reset();	
};


#endif //PACMAN_SMALLFOOD_H
