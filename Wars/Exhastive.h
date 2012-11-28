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

std::vector<int> exhastive( ConnMatrix connections ) {
    std::vector<int> currentBest;
    std::vector<int> currentBestCost;

    // get a first permuate
    for ( int i = 0; i < connections.size(); ++i ) {
        currentBest.append( i );
    }

    std::sort( currentBest.begin(), currentBest.end() );

    // for each permutation: 
    //    see if it beats the current champ

}

