#include <SFML/Graphics.hpp>
#include "Engine/Node.h"
#include "Engine/DynamicObject.h"
#include "Engine/Player.h"
#include "Engine/NodesGenerator.h"
#include "WallsGenerator.h"
#include <iostream>
#include <ctime>
#include "Engine/GameManager.h"
#include <sstream>

const int Distance = 23; 

int main()
{
	srand( time( NULL ) );
	
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Pacman");
	window.setFramerateLimit ( 60 );
	GameManager game;
	sf::Font font;
	font.loadFromFile( "tahoma.ttf" ) ;
	sf::Text score;
	sf::Text lifes;
	score.setFont(font);
	score.setColor( sf::Color::White );
	score.setCharacterSize( 20 );
	score.setPosition( sf::Vector2f(100.f, 750.f ) );
	lifes.setFont(font);
	lifes.setColor( sf::Color::White );
	lifes.setCharacterSize( 20 );
	lifes.setPosition( sf::Vector2f(50.f, 750.f ) );

	sf::VertexArray V( sf::PrimitiveType::Lines, 0 );
	WallsGenerator generator( V, sf::Vector2f(15.f,15.f) );
	while (window.isOpen())
	{
		sf::Event event;
        	while (window.pollEvent(event))
        	{
        		if (event.type == sf::Event::Closed){
    				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A ) {
				game.player ->lastWantedDirection = DynamicObject::LEFT;
				if ( game.state == GameManager::BEFOREROUND || game.state == GameManager::LIFELOST ) game.isStartWanted = true;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W ) game.player ->lastWantedDirection = DynamicObject::UP;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S ) game.player ->lastWantedDirection = DynamicObject::DOWN;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D ) {
				game.player ->lastWantedDirection = DynamicObject::RIGHT;
				if ( game.state == GameManager::BEFOREROUND || game.state == GameManager::LIFELOST ) game.isStartWanted = true;
			}
        	}
		
		game.action();
        	window.clear();
		for ( Node * n : game.nodes ){
			window.draw(*n);
		}
		for ( DynamicObject * n : game.dynamicObjects ){
        		window.draw(*n);
		}
		
		window.draw(V);

		std::ostringstream ss;
		std::ostringstream ss2;
		ss << game.points;
		std::string str = ss.str();
		score.setString ( str );
		window.draw(score);

		ss2 << game.lifes;
		str = ss2.str();
		lifes.setString ( str );
		window.draw(lifes);

        	window.display();
	}	
	return 0;
}
