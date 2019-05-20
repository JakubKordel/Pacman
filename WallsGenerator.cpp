//
// Created by Jakub Kordel on 12.05.2019
//

#include "WallsGenerator.h"

const int Distance = 23; 

WallsGenerator::WallsGenerator( sf::VertexArray & walls, sf::Vector2f leftUpCorner ) : rows(33), collumns(30), distance( Distance ) {
	initializeWallsScheme();
	for ( int j = 1; j < rows - 1 ; ++j ){
		for ( int i = 1; i < collumns - 1; ++i ){
			if ( tab[j][i] && tab[j][i+1] && (!(tab[j-1][i] && tab[j-1][i+1]) || !(tab[j+1][i] && tab[j+1][i+1]) ) ){
				walls.resize( walls.getVertexCount() + 2 );
				walls[walls.getVertexCount() - 2] = sf::Vector2f( (i-1)*(distance+1), (j-1)*(distance + 1 ) ) + leftUpCorner ;
				walls[walls.getVertexCount() - 1] = sf::Vector2f( i*(distance+1), (j-1)*(distance + 1 ) ) + leftUpCorner ;
			}

			if ( tab[j][i] && tab[j+1][i] && (!(tab[j][i-1] && tab[j+1][i-1]) || !(tab[j][i+1] && tab[j+1][i+1]) ) ){
				walls.resize( walls.getVertexCount() + 2 );
				walls[walls.getVertexCount() - 2] = sf::Vector2f( (i-1)*(distance+1), (j-1)*(distance + 1 ) ) + leftUpCorner ;
				walls[walls.getVertexCount() - 1] = sf::Vector2f( (i-1)*(distance+1), j*(distance + 1 ) ) + leftUpCorner ;				
			}
		}
	}

	for ( unsigned int i = 0; i < walls.getVertexCount(); ++i ) walls[i].color = sf::Color(30,89,69);  
}

void WallsGenerator::initializeWallsScheme(){
	tab = new bool * [rows] ;

	tab[0]  = new bool [collumns] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0, 0 };
	tab[1]  = new bool [collumns] { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1, 1, 1, 0 };
	tab[2]  = new bool [collumns] { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 1, 0 };
	tab[3]  = new bool [collumns] { 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 ,0 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1, 0, 1, 0 };
	tab[4]  = new bool [collumns] { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1 ,0 ,1 ,0 ,1 ,0 ,1 ,0 ,0 ,1, 0, 1, 0 };
	tab[5]  = new bool [collumns] { 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 ,0 ,1 ,1 ,1 ,0 ,1 ,0 ,0 ,1, 0, 1, 0 };
	tab[6]  = new bool [collumns] { 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,1, 0, 1, 0 };
	tab[7]  = new bool [collumns] { 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,0 ,1, 0, 1, 0 };
	tab[8]  = new bool [collumns] { 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1, 0, 1, 0 };
	tab[9]  = new bool [collumns] { 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0, 0, 1, 0 };
	tab[10] = new bool [collumns] { 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1, 1, 1, 0 };
	tab[11] = new bool [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,0 ,0, 0, 0, 0 };
	tab[12] = new bool [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0, 0, 0, 0 };
	tab[13] = new bool [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,0 ,0, 0, 0, 0 };
	tab[14] = new bool [collumns] { 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1, 1, 1, 0 };
	tab[15] = new bool [collumns] { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0 ,1 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0, 0, 0, 0 };
	tab[16] = new bool [collumns] { 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1, 1, 1, 0 };
	tab[17] = new bool [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,0 ,0, 0, 0, 0 };
	tab[18] = new bool [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0, 0, 0, 0 };
	tab[19] = new bool [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,0 ,0, 0, 0, 0 };
	tab[20] = new bool [collumns] { 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1, 1, 1, 0 };
	tab[21] = new bool [collumns] { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 1, 0 };
	tab[22] = new bool [collumns] { 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,0 ,1, 1, 1, 0 };
	tab[23] = new bool [collumns] { 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,0 ,1, 1, 1, 0 };
	tab[24] = new bool [collumns] { 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1 ,1 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0, 0, 1, 0 };
	tab[25] = new bool [collumns] { 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1, 0, 1, 0 };
	tab[26] = new bool [collumns] { 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1, 0, 1, 0 };
	tab[27] = new bool [collumns] { 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1, 0, 1, 0 };
	tab[28] = new bool [collumns] { 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1, 0, 1, 0 };
	tab[29] = new bool [collumns] { 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1, 0, 1, 0 };
	tab[30] = new bool [collumns] { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 1, 0 };
	tab[31] = new bool [collumns] { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1, 1, 1, 0 };
	tab[32] = new bool [collumns] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0, 0 };
}
	
WallsGenerator::~WallsGenerator(){
	for ( int i = 0; i<rows; ++i){
		delete [] tab[i];
	}
	delete [] tab;
}
