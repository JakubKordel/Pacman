//
// Created by Jakub Kordel on 13.05.2019
//

#ifndef PACMAN_SPECIALFOOD_H
#define PACMAN_SPECIALFOOD_H

#include "Food.h"
#include <SFML/Graphics.hpp>

class SpecialFood : public Food {

public:
	SpecialFood( sf::Vector2f vector, bool u, bool d, bool l, bool r );

};


#endif //PACMAN_SPECIALFOOD_H
