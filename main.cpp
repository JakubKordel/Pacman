#include <SFML/Graphics.hpp>
#include "Engine/Node.h"
#include "Engine/DynamicObject.h"
#include "Engine/Player.h"
#include "Engine/NodesGenerator.h"
#include "Engine/SmallFood.h"
#include "Engine/BigFood.h"
#include "Engine/SpecialFood.h"
#include "Engine/Tunnel.h"
#include "Engine/Ghost.h"
#include "Engine/Blinky.h"
#include "Engine/Pinky.h"
#include <iostream>
#include <ctime>

const int Distance = 23; 

int main()
{
	srand( time( NULL ) );
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Pacman");
	std::vector<Node*> nodes;
	std::vector<SmallFood*> smallFoods;
	std::vector<BigFood*> bigFoods;
	std::vector<SpecialFood*> specialFoods;
	std::vector<Tunnel*> tunnels;
	std::vector<DynamicObject*> dynamicObjects;
	std::vector<Ghost*> ghosts;
	NodesGenerator generator( nodes, smallFoods, bigFoods, specialFoods, tunnels, sf::Vector2f(15.f,15.f));

	Player * player;
	Ghost * ghost;
	DynamicObject * dynamicObject;
	dynamicObject = player = new Player(sf::Vector2f(9.f, 9.f), nodes );
	dynamicObjects.push_back(dynamicObject);

	dynamicObject = ghost = new Blinky(sf::Vector2f(9.f, 9.f), nodes, player, &tunnels );
	dynamicObjects.push_back(dynamicObject);
	ghosts.push_back(ghost);
	ghost -> setPosition( sf::Vector2f( 39.f, 39.f ) );

	dynamicObject = ghost = new Pinky(sf::Vector2f(9.f, 9.f), nodes, player, &tunnels );
	dynamicObjects.push_back(dynamicObject);
	ghosts.push_back(ghost);
	ghost -> setPosition( sf::Vector2f( 39.f, 39.f ) );		
	

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
		for ( Ghost * n : ghosts ){
        		n ->move();
		}
		player ->move();
		for ( Node * n : nodes ){
			window.draw(*n);
		}
		for ( DynamicObject * n : dynamicObjects ){
        		window.draw(*n);
		}
        	window.display();
	}
	
		
	return 0;
}
