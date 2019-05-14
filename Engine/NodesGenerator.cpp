//
// Created by Jakub Kordel on 12.05.2019
//

#include "NodesGenerator.h"

const int Distance = 23; 

NodesGenerator::NodesGenerator( std::vector<Node*> & nodes, std::vector<SmallFood*> & smallFoods, std::vector<BigFood*> & bigFoods, std::vector<SpecialFood*> & specialFoods, 
	std::vector<Tunnel*> & tunnels, sf::Vector2f leftUpCorner ) : rows(31), collumns(28), distance( Distance ) {
	initializeMapScheme();
	bool up, down, left, right;
	Node * node;
	SmallFood * smallFood;
	BigFood * bigFood;
	SpecialFood * specialFood;
	Tunnel * tunnel;
	for ( int j = 1; j < rows - 1 ; ++j ){
		for ( int i = 1; i < collumns - 1; ++i ){
			if ( tab[j][i] != 0 ){
				if ( tab[j-1][i] != 0  ) up = 1; else  up = 0 ; 
				if ( tab[j+1][i] != 0  ) down = 1; else  down = 0 ; 
				if ( tab[j][i-1] != 0  ) left = 1; else  left = 0 ;
				if ( tab[j][i+1] != 0  ) right = 1; else right = 0 ;
				switch (tab[j][i]){
					case 1:
					  node = smallFood = new SmallFood( sf::Vector2f( i*(distance+1), j*(distance + 1 )) + leftUpCorner , up, down, left, right );
					  smallFoods.push_back( smallFood );
					  break;
					case 2:
					  node = bigFood = new BigFood( sf::Vector2f( i*(distance+1), j*(distance + 1 )) + leftUpCorner , up, down, left, right );
					  bigFoods.push_back( bigFood );
					  break;
					case 3:
					  node = new Node( sf::Vector2f( i*(distance+1), j*(distance + 1 )) + leftUpCorner , up, down, left, right );
					  break;
					case 4:
					  node = tunnel = new Tunnel( sf::Vector2f( i*(distance+1), j*(distance + 1 )) + leftUpCorner , up, down, left, right );
					  tunnels.push_back( tunnel );
					  break;
					case 5:
					  node = specialFood = new SpecialFood( sf::Vector2f( i*(distance+1), j*(distance + 1 )) + leftUpCorner , up, down, left, right );
					  specialFoods.push_back( specialFood );
					  break;
				}
				nodes.push_back( node );
			}		
		}
	}
	int mainCounter = 0;
	int counter2;
	bool isFound;
	for ( int j = 1; j < rows - 1 ; ++j ){
		for ( int i = 1; i < collumns - 1; ++i ){
			if ( tab[j][i] ){

				if ( nodes[mainCounter] -> up )	{
					counter2 = 0;	
					isFound = false;
					for ( int n = 1; n < rows - 1 ; ++n){
						for ( int m = 1; m < collumns - 1; ++m ){
							if ( tab[n][m] ){
								if ( n == j-1 && m == i ){
									isFound = true;
									break;
								} else ++counter2;
							}	
						}
						if ( isFound ) break;	
					}
					nodes[mainCounter] -> nodeUp = nodes[counter2];
				} else nodes[mainCounter] -> nodeUp = nullptr;

				if ( nodes[mainCounter] -> down )	{
					counter2 = 0;	
					isFound = false;
					for ( int n = 1; n < rows - 1 ; ++n ){
						for ( int m = 1; m < collumns - 1; ++m ){
							if ( tab[n][m] ){
								if ( n == j+1 && m == i ){
									isFound = true;
									break;
								} else ++counter2;
							}	
						}
						if ( isFound ) break;	
					}
					nodes[mainCounter] -> nodeDown = nodes[counter2];
				} else nodes[mainCounter] -> nodeDown = nullptr;

				if ( nodes[mainCounter] -> left && ( j != 14 || i != 1 ) )	{
					counter2 = 0;	
					isFound = false;
					for ( int n = 1; n < rows - 1 ; ++n ){
						for ( int m = 1; m < collumns - 1; ++m ){
							if ( tab[n][m] ){
								if ( n == j && m == i-1 ){
									isFound = true;
									break;
								} else ++counter2;	
							}
						}
						if ( isFound ) break;	
					}
					nodes[mainCounter] -> nodeLeft = nodes[counter2];
				} else nodes[mainCounter] -> nodeLeft = nullptr;

				if ( nodes[mainCounter] -> right && ( j != 14 || i != collumns - 2 )  ){
					counter2 = 0;	
					isFound = false;
					for ( int n = 1; n < rows - 1 ; ++n ){
						for ( int m = 1; m < collumns - 1; ++m ){
							if ( tab[n][m] ){
								if ( n == j && m == i + 1 ){
									isFound = true;
									break;
								} else ++counter2;	
							}
						}
						if ( isFound ) break;	
					}
					nodes[mainCounter] -> nodeRight = nodes[counter2];
				}else nodes[mainCounter] -> nodeRight = nullptr;
			++mainCounter;
			}
		}
	}
	tunnels[0] -> nodeLeft = tunnels[1] ;
	tunnels[1] -> nodeRight = tunnels[0];	
	tunnels[0] -> direction = DynamicObject::LEFT;	
	tunnels[1] -> direction = DynamicObject::RIGHT;			
}

//0 - no Node, 1 - SmallFool, 2 - BigFood, 3 - simple Node, 4 - Tunnel, 5 - SpecialFood

void NodesGenerator::initializeMapScheme(){
	tab = new int * [rows] ;
	
	tab[0]  = new int [collumns] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 };
	tab[1]  = new int [collumns] { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1, 1, 0 };
	tab[2]  = new int [collumns] { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[3]  = new int [collumns] { 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 2, 0 };
	tab[4]  = new int [collumns] { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[5]  = new int [collumns] { 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[6]  = new int [collumns] { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[7]  = new int [collumns] { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[8]  = new int [collumns] { 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,0 ,0 ,1 ,1 ,1 ,1 ,1, 1, 0 };
	tab[9]  = new int [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0 ,0 ,3 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[10] = new int [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0 ,0 ,3 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[11] = new int [collumns] { 0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 ,3 ,3 ,3 ,3 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[12] = new int [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0 ,0 ,3 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[13] = new int [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0 ,0 ,3 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[14] = new int [collumns] { 3, 4, 3, 3, 3, 3, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0 ,0 ,3 ,0 ,0 ,1 ,3 ,3 ,3 ,3, 4, 3 };
	tab[15] = new int [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0 ,0 ,3 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[16] = new int [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0 ,0 ,3 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[17] = new int [collumns] { 0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 ,3 ,3 ,3 ,3 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[18] = new int [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[19] = new int [collumns] { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 0, 0 };
	tab[20] = new int [collumns] { 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1, 2, 0 };
	tab[21] = new int [collumns] { 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,0, 0, 0 };
	tab[22] = new int [collumns] { 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,0, 0, 0 };
	tab[23] = new int [collumns] { 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,1 ,1, 1, 0 };
	tab[24] = new int [collumns] { 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,0 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[25] = new int [collumns] { 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,0 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1, 0 };
	tab[26] = new int [collumns] { 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0, 1, 0 };
	tab[27] = new int [collumns] { 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0, 1, 0 };
	tab[28] = new int [collumns] { 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0, 1, 0 };
	tab[29] = new int [collumns] { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1, 1, 0 };
	tab[30] = new int [collumns] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 };
} 

NodesGenerator::~NodesGenerator(){
	for ( int i = 0; i<rows; ++i){
		delete [] tab[i];
	}
	delete [] tab;
}
