//
// Created by Jakub Kordel on 16.05.2019
//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H

#include "Node.h"
#include "DynamicObject.h"
#include "Player.h"
#include "cstdlib"
#include "Tunnel.h"

/// Reprezentuje duszka poruszającego się w tunelach
class Ghost : public DynamicObject {

public:

	enum State { RANDOM, HUNT, ESCAPE };

	State state;

	Player * player;
	std::vector<Tunnel*> * tunnels;
	bool isInCage;
	size_t timeInCage;

	int randomization; // < 100
	sf::Vector2f positionInCage;
	Ghost ( const sf::Vector2f & vector, std::vector<Node*> & nodesVector, Player * playerPointer, std::vector<Tunnel*> * tunnels );
	/// Wykonuje ruch duszka, sposób wykonania ruchu zależy od atrybutu state oraz typu duszka. 
	virtual void move ( ){}
	/// Zmienia kierunek ruchu duszka na przeciwny 
	void reverseMovement(); 
	/// Ustwaia duszka w tunelu, w pozycji startowej
	void respawn();
	/// Wykonuje ruch duszka w losowy ( oczywiście możliwy ) sposób
	void randomMove();
	/// Wykonuje ruch duszka zgodnie z taktyka ducha Blinky ( można poczytać na wikipedii )
	void huntMoveLikeBlinky();
	/// Wykonuje ruch duszka zgodnie z taktyką ducha Pinky ( moźna poczytać na wikipedii )
	void huntMoveLikePinky();
	/// Wykonuje ruch w taki sposób by uciekać przed graczem
	void escapeMove();
	/// Umieszcza gracza w klatce. Wyłącza go z gry
	void goToCage();
	int playerPosition(); //   2 1 0
			      //   3 G 7  G - ghost 
			      //   4 5 6
};


#endif //PACMAN_GHOST_H
