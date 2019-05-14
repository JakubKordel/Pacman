//
// Created by Jakub Kordel on 13.05.2019
//

#include "Food.h"

Food::Food( sf::Vector2f vector, bool u, bool d, bool l, bool r ) : Node( vector, u, d, l, r )  {
	isEaten = false;
}
