//
// Created by Jakub Kordel on 13.05.2019
//

#ifndef PACMAN_SMALLFOOD_H
#define PACMAN_SMALLFOOD_H

#include "Food.h"
#include <SFML/Graphics.hpp>

class SmallFood : public Food {

public:
	SmallFood( sf::Vector2f vector, bool u, bool d, bool l, bool r );

};


#endif //PACMAN_SMALLFOOD_H
