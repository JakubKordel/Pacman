//
// Created by Jakub Kordel on 12.05.2019
//

#ifndef PACMAN_NODESGENERATOR_H
#define PACMAN_NODESGENERATOR_H

#include "Node.h"
#include <SFML/Graphics.hpp>

class NodesGenerator {
public:
	NodesGenerator( std::vector<Node> & nodes, bool ** tab, int rows, int collumns, int distance, sf::Vector2f leftUpCorner ); //distance - liczba pixeli pomiedzy wezlami
	//Tablica musi miec wartosci false na krawedziach tablicy
};


#endif //PACMAN_NODESGENERATOR_H
