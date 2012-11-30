/*
 * =====================================================================================
 *
 *       Filename:  Helper.h
 *
 *    Description:  Just some helper functions
 *
 *        Version:  1.0
 *        Created:  11/30/2012 11:29:25 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew DeMaria (muff1nman), ademaria@mines.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include "ConnMatrix.h"
#include "debug.h"
#include <climits>
#pragma once

// calculate the absolute distance between two unique componets in a // array.  (i.e. if they are adjacent, return 1.  If there is a
// component between them return 2 )
// IF the components don't exisit return -1
int distance(const std::vector<int>& path, int one, int two ) {
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
int calculatePathCost(const ConnMatrix& connections, const std::vector<int>& path ) {
    int cost = 0;
    // for each pair of componets, ( i and j) add the distance *
    // number of connections between those components to the cost
    for ( unsigned int i = 0; i < connections.size(); ++i ) {
        for( unsigned int j = i + 1; j < connections[i].size(); ++j ) {
            cost += distance( path, i, j ) * connections[i][j];
        }
    }

    return cost;
}

void printVector( const std::vector<int>& toPrint ) {
    for ( unsigned int i = 0 ; i < toPrint.size(); ++i ) {
        std::cout << toPrint[i] << " ";
    }
    std::cout << std::endl;
}

