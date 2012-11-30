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

#pragma once

std::vector<int> exhastive(const ConnMatrix& connections ) {
    std::vector<int> currentBest;
    std::vector<int> current;
    int currentBestCost = INT_MAX;


    // get a first permuate
    for ( int i = 0; (unsigned int)i < connections.size(); ++i ) {
        current.push_back( i );
    }

    // dont need because the above puts them into order on creation
    //std::sort( current.begin(), current.end() );

    // for each permutation: 
    //    see if it beats the current champ
    int currentCost;
    while ( std::next_permutation( current.begin(), current.end()) ) {
#ifdef D_EXHASTIVE
        std::cout << "Permutation: ";
        printVector( current );
        std::cout << "Best: cost(" << currentBestCost <<  ") ";
        printVector( currentBest );
#endif

        currentCost = calculatePathCost( connections, current );
        if ( currentCost < currentBestCost ) {
            currentBest = current;
            currentBestCost = currentCost;
        }

    }

#ifdef D_EXHASTIVE
    std::cout << "Permutation: ";
    printVector( current );
#endif

    return currentBest;

}



