//
// Created by Jakub Kordel on 11.05.2019 
//

#ifndef PACMAN_NODE_H
#define PACMAN_NODE_H

#include <SFML/Graphics.hpp>

class Node : public sf::RectangleShape {
public:
	const bool up;
	const bool down;
	const bool left;
	const bool right;
	//const int x; // 
	//const int y; //x, y - okresla pozycje na mapie wzgledem innych wezlow ! Nie sa to wspolrzedne w pixelach !

	Node ( sf::Vector2f vector, bool u, bool d, bool l, bool r );

	bool isFood;
	bool isEaten;
};


#endif //PACMAN_NODE_H
