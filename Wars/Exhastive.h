/*
 * =====================================================================================
 *
 *       Filename:  Exhastive.h
 *
 *    Description:  An exhastive attempt for an algorithm
 *
 *        Version:  1.0
 *        Created:  11/28/2012 01:44:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew DeMaria (muff1nman), ademaria@mines.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdlib>
#include "ConnMatrix.h"
#include <algorithm>
#include <vector>
#include <climits>
#include "debug.h"
#include "Helper.h"

// calculate the absolute distance between two unique componets in a
// array.  (i.e. if they are adjacent, return 1.  If there is a
// component between them return 2 )
// IF the components don't exisit return -1
int distance( std::vector<int> path, int one, int two ) {
    std::vector<int>::const_iterator one_index = std::find( path.begin(), path.end(), one);
    std::vector<int>::const_iterator two_index = std::find( path.begin(), path.end(), two);

    if ( one_index == path.end() || two_index == path.end() ) {
        return -1;
    }

    return abs( one_index - two_index );
}

// calculates the cost of a given path using the supplied connection
// matrix. The connection matrix is indexed base 0 so there are
// components 0 to (n - 1)
int calculatePathCost( ConnMatrix connections, std::vector<int> path ) {
    int cost = 0;
    // for each pair of componets, ( i and j) add the distance *
    // number of connections between those components to the cost
    for ( int i = 0; i < connections.size(); ++i ) {
        for( int j = i + 1; j < connections[i].size(); ++j ) {
            cost += distance( path, i, j ) * connections[i][j];
        }
    }

    return cost;
}


std::vector<int> exhastive( ConnMatrix connections ) {
    std::vector<int> currentBest;
    std::vector<int> current;
    int currentBestCost = INT_MAX;

    // get a first permuate
    for ( int i = 0; i < connections.size(); ++i ) {
        current.push_back( i );
    }

    std::sort( current.begin(), current.end() );

    // for each permutation: 
    //    see if it beats the current champ
    int currentCost;
    while ( std::next_permutation( current.begin(), current.end() ) ) {
        currentCost = calculatePathCost( connections, current );
        if ( currentCost < currentBestCost ) {
            currentBest = current;
        }

    }

    return currentBest;

}



