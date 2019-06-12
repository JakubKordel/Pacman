//
// Created by Jakub Kordel on 12.05.2019
//

#ifndef PACMAN_NODESGENERATOR_H
#define PACMAN_NODESGENERATOR_H

#include "Node.h"
#include "SmallFood.h"
#include "BigFood.h"
#include "SpecialFood.h"
#include "Tunnel.h"
#include <SFML/Graphics.hpp>

///Generuje mape węzłów ( zwykłe węzły, jedzienie i teleportujący tunel )
class NodesGenerator {
	const int rows;
	const int collumns;
	const int distance;
	int **tab; /// Przechowuje schemat mapy
	/// Inicializuje tablice tab
	void initializeMapScheme();
public:
	NodesGenerator( std::vector<Node*> & nodes, std::vector<SmallFood*> & smallFoods, std::vector<BigFood*> & bigFoods, std::vector<SpecialFood*> & specialFoods, 
	std::vector<Tunnel*> & tunnels, sf::Vector2f leftUpCorner ); 
	~NodesGenerator();
};


#endif //PACMAN_NODESGENERATOR_H
