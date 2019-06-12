//
// Created by Jakub Kordel on 11.05.2019
//

#ifndef PACMAN_DYNAMICOBJECT_H
#define PACMAN_DYNAMICOBJECT_H 

#include <SFML/Graphics.hpp>

#include "Node.h"

class Tunnel;
class GameManager;

/// Klasa reprezentująca obiekty poruszające się od węzła do węzła
class DynamicObject : public sf::RectangleShape {

friend class Tunnel;
friend class GameManager;

public:
	enum Direction { UP, DOWN, LEFT, RIGHT, NONE };

protected:
	std::vector<Node*> & nodes; ///< Zbiór węzłów na mapie
	Direction movement; ///< kierunek następnego ruchu obiektu 
	float speedValue; // > 0 
	sf::Vector2f speed;
	/// Sprawdza czy obiekt znajduje się w węźle 
	/**
	Jeśli obiekt znajduje się w węźle, metoda zwraca wskaźnik na ten węzeł.
	Jeśli obiekt nie znajduje się w węźle, zwracany jest wskaźnik nullptr
	*/
 	Node * isInNode();
	Node * lastNode;
	sf::Vector2f spawnPoint;
	/// Inicjalizuje obiekt dynamiczny
	/**
	\param vector określa położenie obiektu 
	\param nodesVector wektor przechowujący wskaźniki na wszystkie węzły z planszy
	*/
	DynamicObject( const sf::Vector2f & vector, std::vector<Node*> & nodesVector );
	/// Metoda przesuwa obiekt
	/**
	Metoda przesuwa obiekt o pewną ilość pikseli określoną przez wartość atrybutu speedValue, w kierunku określonym przez wartość atrybutu movement. 
	*/	
	void move();
	///Metoda ustawia atrybut movement
	void changeMovement( const Direction & direction );
public:
	/// Metoda ustawia obiekt w punkcie określonym przez atrybut spawnPoint.
	void respawn();
	Direction lastWantedDirection;
};


#endif //PACMAN_DYNAMICOBJECT_H
