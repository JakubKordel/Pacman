//
// Created by Jakub Kordel on 13.05.2019
//

#ifndef PACMAN_FOOD_H
#define PACMAN_FOOD_H

#include "Node.h"
#include <SFML/Graphics.hpp>

class Food : public Node {

protected:
	bool isEaten;

public:
	Food( sf::Vector2f vector, bool u, bool d, bool l, bool r );
};


#endif //PACMAN_FOOD_H
