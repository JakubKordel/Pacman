//
// Created by Jakub Kordel on 11.05.2019 
//

#ifndef PACMAN_NODE_H
#define PACMAN_NODE_H

#include <SFML/Graphics.hpp>

class NodesGenerator;

/// Reprezentuje węzel. Pewny punkt na mapie
class Node : public sf::RectangleShape {
	friend class NodesGenerator;
public:
	const bool up;
	const bool down;
	const bool left;
	const bool right;

private:
	
	Node * nodeUp;
	Node * nodeDown;
	Node * nodeLeft;
	Node * nodeRight;

public:
	/**
	\param vector reprezentuje położenie węzła
	\param u posiadanie górnego sąsiada 
	\param d posiadanie dolnego sąsiada 
	\param l posiadanie lewego sąsiada 
	\param r posiadanie prawego sąsiada 
	*/
	Node ( sf::Vector2f vector, bool u, bool d, bool l, bool r );
	/// Funkcja wywoływana przez obiekty wchodzące do węzła 
	virtual void visit(){}
	///Zwraca wskaźnik na sąsiadujący węzeł z góry 
	Node * getNodeUp();
	///Zwraca wskaźnik na sąsiadujący węzeł z dołu
	Node * getNodeDown();
	///Zwraca wskaźnik na sąsiadujący węzeł z lewej
	Node * getNodeLeft();
	///Zwraca wskaźnik na sąsiadujący węzeł z prawej
	Node * getNodeRight();
};


#endif //PACMAN_NODE_H
