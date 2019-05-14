#include <SFML/Graphics.hpp>
#include "Engine/Node.h"
#include "Engine/DynamicObject.h"
#include "Engine/Player.h"
#include "Engine/NodesGenerator.h"
#include "Engine/SmallFood.h"
#include "Engine/BigFood.h"
#include "Engine/SpecialFood.h"
#include "Engine/Tunnel.h"
#include <iostream>

const int Distance = 23; 

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Pacman");
	std::vector<Node*> nodes;
	std::vector<SmallFood*> smallFoods;
	std::vector<BigFood*> bigFoods;
	std::vector<SpecialFood*> specialFoods;
	std::vector<Tunnel*> tunnels;
	std::vector<DynamicObject*> dynamicObjects;
	NodesGenerator generator( nodes, smallFoods, bigFoods, specialFoods, tunnels, sf::Vector2f(15.f,15.f));

	Player * player;
	DynamicObject * dynamicObject;
	dynamicObject = player = new Player(sf::Vector2f(9.f, 9.f));
	player ->setPosition(39, 39);
	dynamicObjects.push_back(dynamicObject);	

	tunnels[0] -> objects = dynamicObjects;
	tunnels[1] -> objects = dynamicObjects;

	while (window.isOpen())
	{
		sf::Event event;
        	while (window.pollEvent(event))
        	{
        		if (event.type == sf::Event::Closed)
        		window.close();
			
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A ) player ->lastWantedDirection = DynamicObject::LEFT;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W ) player ->lastWantedDirection = DynamicObject::UP;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S ) player ->lastWantedDirection = DynamicObject::DOWN;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D ) player ->lastWantedDirection = DynamicObject::RIGHT;
        	}
		
        	window.clear();
		player ->move(nodes);
		for ( Node * n : nodes ){
			window.draw(*n);
		}
        	window.draw(*player);
        	window.display();
	}
	
		
	return 0;
}
