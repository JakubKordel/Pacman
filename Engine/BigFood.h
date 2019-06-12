//
// Created by Jakub Kordel on 13.05.2019
//

#ifndef PACMAN_BIGFOOD_H_INCLUDED
#define PACMAN_BIGFOOD_H_INCLUDED

#include "Food.h"
#include <SFML/Graphics.hpp>

///Reprezentuje grube jedzenie, przeznaczone do zjedzenia przez gracza
class BigFood : public Food {

public:
	BigFood( sf::Vector2f vector, bool u, bool d, bool l, bool r );
	/**
	Metoda powoduje ustawienie duszków w tryb ucieczki i ustawia kierunek ich ruchu na przeciwny. Obiekt przechodzi w tryb 'zjedzony'. 
	Dodaje 40 do licznika punktów gracza.
	*/
	void visit();
	/// Ustawia jedzenie jako niezjedzone
	void reset();
};


#endif //PACMAN_BIGFOOD_H
