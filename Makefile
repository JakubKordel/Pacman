CFLAGS=-Wall -pedantic -std=c++11
SFML=-lsfml-graphics -lsfml-window -lsfml-system

compile: main.o ./Engine/Node.o ./Engine/Node.h ./Engine/DynamicObject.o ./Engine/DynamicObject.h ./Engine/Player.o ./Engine/Player.h ./Engine/NodesGenerator.o ./Engine/NodesGenerator.h WallsGenerator.o WallsGenerator.h ./Engine/Food.o ./Engine/Food.h ./Engine/SmallFood.o ./Engine/SmallFood.h ./Engine/BigFood.o ./Engine/BigFood.h ./Engine/SpecialFood.o ./Engine/SpecialFood.h ./Engine/Tunnel.o ./Engine/Tunnel.h ./Engine/Ghost.o ./Engine/Ghost.h ./Engine/Blinky.o ./Engine/Blinky.h ./Engine/Pinky.o ./Engine/Pinky.h ./Engine/Clyde.o ./Engine/Clyde.h ./Engine/Inky.o ./Engine/Inky.h ./Engine/GameManager.o ./Engine/GameManager.h
	g++ $(CFLAGS) $(SFML) main.o ./Engine/Node.o ./Engine/DynamicObject.o  ./Engine/Player.o ./Engine/NodesGenerator.o WallsGenerator.o ./Engine/Food.o ./Engine/SmallFood.o ./Engine/BigFood.o ./Engine/SpecialFood.o ./Engine/Tunnel.o ./Engine/Ghost.o ./Engine/Blinky.o ./Engine/Pinky.o ./Engine/Clyde.o ./Engine/Inky.o ./Engine/GameManager.o -o Pacman

main.o: main.cpp 
	g++ -c $(CFLAGS) main.cpp

Node.o: ./Engine/Node.cpp ./Engine/Node.h
	g++ -c $(CFLAGS) ./Engine/Node.cpp

DynamicObject.o: ./Engine/DynamicObject.cpp ./Engine/DynamicObject.h
	g++ -c $(CFLAGS) ./Engine/DynamicObject.cpp

Player.o: ./Engine/Player.cpp ./Engine/Player.h
	g++ -c $(CFLAGS) ./Engine/Player.cpp

NodesGenerator.o: ./Engine/NodesGenerator.cpp ./Engine/NodesGenerator.h
	g++ -c $(CFLAGS) ./Engine/NodesGenerator.cpp

WallsGenerator.o: WallsGenerator.cpp WallsGenerator.h
	g++ -c $(CFLAGS) WallsGenerator.cpp

Food.o: ./Engine/Food.cpp ./Engine/Food.h
	g++ -c $(CFLAGS) ./Engine/Food.cpp

SmallFood.o: ./Engine/SmallFood.cpp ./Engine/SmallFood.h
	g++ -c $(CFLAGS) ./Engine/SmallFood.cpp

BigFood.o: ./Engine/BigFood.cpp ./Engine/BigFood.h
	g++ -c $(CFLAGS) ./Engine/BigFood.cpp

SpecialFood.o: ./Engine/SpecialFood.cpp ./Engine/SpecialFood.h
	g++ -c $(CFLAGS) ./Engine/SpecialFood.cpp

Tunnel.o: ./Engine/Tunnel.cpp ./Engine/Tunnel.h
	g++ -c $(CFLAGS) ./Engine/Tunnel.cpp

Ghost.o: ./Engine/Ghost.cpp ./Engine/Ghost.h
	g++ -c $(CFLAGS) ./Engine/Ghost.cpp

Blinky.o: ./Engine/Blinky.cpp ./Engine/Blinky.h
	g++ -c $(CFLAGS) ./Engine/Blinky.cpp

Pinky.o: ./Engine/Pinky.cpp ./Engine/Blinky.h
	g++ -c $(CFLAGS) ./Engine/Pinky.cpp

Clyde.o: ./Engine/Clyde.cpp ./Engine/Clyde.h
	g++ -c $(CFLAGS) ./Engine/Clyde.cpp

Inky.o: ./Engine/Inky.cpp ./Engine/Inky.h
	g++ -c $(CFLAGS) ./Engine/Inky.cpp

GameManager.o: ./Engine/GameManager.cpp ./Engine/GameManager.h
	g++ -c $(CFLAGS) ./Engine/GameManager.cpp

debug: 
	g++ $(CFLAGS) $(SFML) main.cpp ./Engine/Node.cpp ./Engine/DynamicObject.cpp ./Engine/Player.cpp ./Engine/NodesGenerator.cpp WallsGenerator.cpp ./Engine/Food.cpp ./Engine/SmallFood.cpp ./Engine/BigFood.cpp ./Engine/SpecialFood.cpp ./Engine/Tunnel.cpp ./Engine/Ghost.cpp ./Engine/Blinky.cpp ./Engine/Pinky.cpp ./Engine/Clyde.cpp ./Engine/Inky.cpp ./Engine/GameManager.cpp -o PacmanDebug
	


