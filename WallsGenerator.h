//
// Created by Jakub Kordel on 19.05.2019
//

#ifndef PACMAN_WALLSGENERATOR_H
#define PACMAN_WALLSGENERATOR_H

#include <SFML/Graphics.hpp>


class WallsGenerator {
	const int rows;
	const int collumns;
	const int distance;
	bool **tab; 
	void initializeWallsScheme();
public:
	WallsGenerator( sf::VertexArray & walls, sf::Vector2f leftUpCorner ); 
	~WallsGenerator();
};


#endif //PACMAN_WALLSGENERATOR_H
