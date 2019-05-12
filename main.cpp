#include <SFML/Graphics.hpp>
#include "Engine/Node.h"
#include "Engine/DynamicObject.h"
#include "Engine/Player.h"
#include "Engine/NodesGenerator.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Pacman");
	int n = 31;
	bool **tab = new bool * [n] ;
	
	tab[0]  = new bool [28] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 };
	tab[1]  = new bool [28] { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1, 1, 0 };
	tab[2]  = new bool [28] { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[3]  = new bool [28] { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[4]  = new bool [28] { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[5]  = new bool [28] { 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[6]  = new bool [28] { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[7]  = new bool [28] { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[8]  = new bool [28] { 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,0 ,0 ,1 ,1 ,1 ,1 ,1, 1, 0 };
	tab[9]  = new bool [28] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,0 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[10] = new bool [28] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,0 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[11] = new bool [28] { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[12] = new bool [28] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,0 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[13] = new bool [28] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,0 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[14] = new bool [28] { 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,0 ,1 ,0 ,0 ,1 ,1 ,1 ,1 ,1, 1, 0 };
	tab[15] = new bool [28] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,0 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[16] = new bool [28] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,0 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[17] = new bool [28] { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[18] = new bool [28] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[19] = new bool [28] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[20] = new bool [28] { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1, 1, 0 };
	tab[21] = new bool [28] { 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,0, 0, 0 };
	tab[22] = new bool [28] { 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,0, 0, 0 };
	tab[23] = new bool [28] { 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,1 ,1, 1, 0 };
	tab[24] = new bool [28] { 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,0 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[25] = new bool [28] { 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,0 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[26] = new bool [28] { 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0, 1, 0 };
	tab[27] = new bool [28] { 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0, 1, 0 };
	tab[28] = new bool [28] { 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0, 1, 0 };
	tab[29] = new bool [28] { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1, 1, 0 };
	tab[30] = new bool [28] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 };
	
	std::vector<Node> nodes;
	NodesGenerator generator( nodes, tab, 28, n, 19, sf::Vector2f(0.f, 0.f));

	for ( int i = 0; i<n; ++i){
		delete [] tab[i];
	}
	delete [] tab;

	Player player(sf::Vector2f(9.f, 9.f));
	player.setPosition(20, 20);

	while (window.isOpen())
	{
		sf::Event event;
        	while (window.pollEvent(event))
        	{
        		if (event.type == sf::Event::Closed)
        		window.close();
			
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A ) player.lastWantedDirection = DynamicObject::LEFT;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W ) player.lastWantedDirection = DynamicObject::UP;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S ) player.lastWantedDirection = DynamicObject::DOWN;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D ) player.lastWantedDirection = DynamicObject::RIGHT;
        	}
		
        	window.clear();
		player.move(nodes);
		for ( Node n : nodes ){
			window.draw(n);
		}
        	window.draw(player);
        	window.display();
	}

	return 0;
}
