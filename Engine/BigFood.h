//
// Created by Jakub Kordel on 13.05.2019
//

#ifndef PACMAN_BIGFOOD_H
#define PACMAN_BIGFOOD_H

#include "Food.h"
#include <SFML/Graphics.hpp>

class GameManager;

class BigFood : public Food {

public:
	BigFood( sf::Vector2f vector, bool u, bool d, bool l, bool r );
	void visit();

	GameManager * game;
};


#endif //PACMAN_BIGFOOD_H
