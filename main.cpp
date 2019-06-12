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
	sf::Text gameOver;
	score.setFont(font);
	score.setColor( sf::Color::White );
	score.setCharacterSize( 20 );
	score.setPosition( sf::Vector2f(100.f, 750.f ) );
	lifes.setFont(font);
	lifes.setColor( sf::Color::White );
	lifes.setCharacterSize( 20 );
	lifes.setPosition( sf::Vector2f(50.f, 750.f ) );
	gameOver.setFont(font);
	gameOver.setColor( sf::Color::Red );
	gameOver.setCharacterSize( 30 );
	gameOver.setPosition( sf::Vector2f(260.f, 330.f ) );
	gameOver.setString( "GAME OVER" );

	sf::VertexArray V( sf::PrimitiveType::Lines, 0 );
	WallsGenerator generator( V, sf::Vector2f(15.f,15.f) );
	while (window.isOpen()){
		sf::Event event;
        	while (window.pollEvent(event)){
        		if (event.type == sf::Event::Closed){
    				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A ) {
				game.player ->lastWantedDirection = DynamicObject::LEFT;
				if ( game.state == GameManager::BEFOREROUND || game.state == GameManager::LIFELOST || game.state == GameManager::LOST ) game.isStartWanted = true;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W ) game.player ->lastWantedDirection = DynamicObject::UP;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S ) game.player ->lastWantedDirection = DynamicObject::DOWN;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D ) {
				game.player ->lastWantedDirection = DynamicObject::RIGHT;
				if ( game.state == GameManager::BEFOREROUND || game.state == GameManager::LIFELOST || GameManager::LOST ) game.isStartWanted = true;
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
		
		if ( game.state == GameManager::LOST ) window.draw(gameOver);

        	window.display();
	}	
	return 0;
}

/*!
\mainpage
\author: Jakub Kordel

Polecenie projektu: Proszę napisać program realizujący grę pacman, z wykorzystujaniem bibliotek graficznych (ma to być program "okienkowy"). Do programu należy dołączyć pełną dokumentację projektu. W implementacji projektu należy wykorzystać dziedziczenie, funkcje wirtualne, obsługę wyjątków.

Sposób rozwiązania

Grę pacman ( https://pl.wikipedia.org/wiki/Pac-Man ) napisałem w języku C++ przy użyciu darmowej biblioteki SFML ( https://www.sfml-dev.org/ ). 
	Głównym problemem było zaprojektowanie systemu poruszania się obiektów ( tzn. gracza oraz czterech duszków )  w tunelach. W moim rozwiązaniu tunele reprezentowane są za pomocą sieci ‘węzłów’, czyli określonych punktów na mapie. Obiekty poruszają się od węzła do węzła  Każdy węzeł przechowuje informacje o czterech sąsiadujących węzłach ( lewy i prawy sąsiad w linii poziomej, górny i dolny sąsiad w linii pionowej ). Sąsiedzi rozmieszczeni są w stałych odległościach. Każdy poruszający się obiekt posiada informacje o ostatnim węźle, w którym się znajdował. W każdej klatce gry sprawdzane jest czy obiekt znalazł się w którymś z sąsiadów ostatniego węzła (Aby dać możliwość zawracania obiektom w dowolnym momencie, sprawdzane jest również czy obiekt nie wrócił do ostatniego węzła) . Jeśli obiekt znalazł się w nowym węźle, ma on możliwość wybrania któregoś z dostępnych kierunków do dalszego poruszania. Jeśli węzeł nie posiada sąsiada w którymś z kierunków, oznacza to, że niedostępne jest wyjście obiektu z tego węzła w tym kierunku ( obiekt napotyka na ścianę tunelu ). Takie rozwiązanie umożliwiło proste wygenerowanie planszy gry ( sieci węzłów ) na podstawie tablicy dwuwymiarowej. 
	Obiekty w grze mogą poruszać się z różnymi prędkościami( zmieniają swoje położenie, w każdej klatce gry, o rożną ilość pikseli ). Z tego powodu, wielkość obszaru sprawdzania czy obiekt znalazł się w węźle jest zależny od wartości prędkości obiektu. Inaczej obiekt mógłby przeskoczyć węzeł, co skutkowałoby wyjściem obiektu poza mapę. Gdy obiekt ‘wchodzi do węzła’ jego pozycja korygowana jest do środka węzła, aby po zmianie kierunku obiekt poruszał się zawsze po tej samej linii. Jako, że węzły ustawione są rzadko w porównaniu do wartości prędkości obiektów, korygowanie jest niezauważalne.  



*/
