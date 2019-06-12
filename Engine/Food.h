//
// Created by Jakub Kordel on 13.05.2019
//

#ifndef PACMAN_FOOD_H
#define PACMAN_FOOD_H

#include "Node.h"
#include <SFML/Graphics.hpp>

class GameManager;

/// Reprezentuje węzły na mapie, które po odwiedzeniu przez gracza zostają 'zjedzone'
class Food : public Node {

protected:
	bool isEaten;

public:
	Food( sf::Vector2f vector, bool u, bool d, bool l, bool r );
	GameManager * game;
};


#endif //PACMAN_FOOD_H
