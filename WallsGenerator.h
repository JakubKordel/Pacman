//
// Created by Jakub Kordel on 19.05.2019
//

#ifndef PACMAN_WALLSGENERATOR_H
#define PACMAN_WALLSGENERATOR_H

#include <SFML/Graphics.hpp>

/// Klasa ma na celu utworzenie zbioru punktów, które po połączeniu mają reprezentować ściany tuneli. Schemat ścian definiowany jest w metodzie initializeWallsScheme() w pliku WallsGenerator.cpp
class WallsGenerator {
	const int rows;
	const int collumns;
	const int distance;
	bool **tab; /// inicjalizowana przez metode initializeWallsScheme 
	/// inicjalizuje dwuwymiarową tablice tab (atrybut)
	void initializeWallsScheme(); 
public:
	/** wypełnia wektor walls punktami, które po połączeniu utworzą ściany tuneli 
		\param walls pusty wektor
		\param leftUpCorner Położenie górnego, lewego rogu wygenerowanego schematu ścian tuneli 
	*/
	WallsGenerator( sf::VertexArray & walls, sf::Vector2f leftUpCorner ); 
	~WallsGenerator();
};


#endif //PACMAN_WALLSGENERATOR_H
