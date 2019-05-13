//
// Created by Jakub Kordel on 13.05.2019
//

#ifndef PACMAN_TUNNEL_H
#define PACMAN_TUNNEL_H

#include "Node.h"
#include <SFML/Graphics.hpp>

class Tunnel : public Node {

public:
	Tunnel( sf::Vector2f vector, bool u, bool d, bool l, bool r );
};


#endif //PACMAN_TUNNEL_H
