//
// Created by Jakub Kordel on 12.05.2019
//

#include "NodesGenerator.h"

NodesGenerator::NodesGenerator( std::vector<Node> & nodes, bool ** tab, int collumns, int rows, int distance, sf::Vector2f leftUpCorner ){
	bool up, down, left, right;
	for ( int j = 1; j < rows - 1 ; ++j ){
		for ( int i = 1; i < collumns - 1; ++i ){
			if ( tab[j][i] ){
				if ( tab[j-1][i] ) up = 1; else up = 0 ;
				if ( tab[j+1][i] ) down = 1; else down = 0 ;
				if ( tab[j][i-1] ) left = 1; else left = 0 ;
				if ( tab[j][i+1] ) right = 1; else right = 0 ;
				Node node( sf::Vector2f( i*(distance+1), j*(distance + 1 )) + leftUpCorner , up, down, left, right);
				nodes.push_back( node );
			}		
		}
	}			
}

   
