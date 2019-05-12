CFLAGS=-Wall -pedantic -std=c++11
SFML=-lsfml-graphics -lsfml-window -lsfml-system

compile: main.o ./Engine/Node.o ./Engine/Node.h ./Engine/DynamicObject.o ./Engine/DynamicObject.h ./Engine/Player.o ./Engine/Player.h ./Engine/NodesGenerator.o ./Engine/NodesGenerator.h
	g++ $(CFLAGS) main.o ./Engine/Node.o ./Engine/DynamicObject.o $(SFML) ./Engine/Player.o ./Engine/NodesGenerator.o -o Pacman

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


