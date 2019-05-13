CFLAGS=-Wall -pedantic -std=c++11
SFML=-lsfml-graphics -lsfml-window -lsfml-system

compile: main.o ./Engine/Node.o ./Engine/Node.h ./Engine/DynamicObject.o ./Engine/DynamicObject.h ./Engine/Player.o ./Engine/Player.h ./Engine/NodesGenerator.o ./Engine/NodesGenerator.h ./Engine/Food.o ./Engine/Food.h ./Engine/SmallFood.o ./Engine/SmallFood.h ./Engine/BigFood.o ./Engine/BigFood.h ./Engine/SpecialFood.o ./Engine/SpecialFood.h ./Engine/Tunnel.o ./Engine/Tunnel.h
	g++ $(CFLAGS) $(SFML) main.o ./Engine/Node.o ./Engine/DynamicObject.o  ./Engine/Player.o ./Engine/NodesGenerator.o ./Engine/Food.o ./Engine/SmallFood.o ./Engine/BigFood.o ./Engine/SpecialFood.o ./Engine/Tunnel.o -o Pacman

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

debug: 
	g++ -g $(CFLAGS) $(SFML) main.cpp ./Engine/Node.cpp ./Engine/DynamicObject.cpp  ./Engine/Player.cpp ./Engine/NodesGenerator.cpp ./Engine/Food.cpp ./Engine/SmallFood.cpp ./Engine/BigFood.cpp ./Engine/SpecialFood.cpp ./Engine/Tunnel.cpp -o PacmanDebug
	


