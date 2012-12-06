/*
 * =====================================================================================
 *
 *       Filename:  driver.cpp
 *
 *    Description:  Driver file for the final project
 *
 *        Version:  1.0
 *        Created:  11/22/2012 01:58:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew DeMaria (muff1nman), ademaria@mines.edu
 *                  Matt Stech (mstech), mstech@mines.edu
 *                  Aakash Shah (aashah), ashah@mines.edu
 *                  Josh Wretlind (joshWretlind), jwretlin@mines.edu
 *   Organization:  Colorado School of Mines
 *
 * =====================================================================================
 */
#include "debug.h"
#include <stdlib.h>
#include <iostream>
#include "input.h"
#include <utility>
#include "ConnMatrix.h"
#include <vector>
#include "Helper.h"
#include "Exhastive.h"
#include "Matt.h"
#include "Andrew.h"

using namespace std;

void checkArgs( int argc, char** argv ) {
    if (argc != 2) {
        cout << "Usage: ./driver <inputfilename>" << endl;
        throw INVALID_ARGUMENTS;
    }
}

int main (int argc, char** argv) {
#ifdef SHOWGROUP
    cout << "    ALGO WARS" << endl;
    cout << "     Group 8" << endl;
    cout << "=================" << endl;
#endif

    try {
        checkArgs( argc, argv );
    } catch( int x ) {
        cout << "Exiting with error status: " << x << endl;
        exit(x);
    }

    ConnMatrix connections;
    try {
        connections = import( argv[1] );
    } catch(  int x ) {
        cout << "Exiting with error status: " << x << endl;
        exit(x);
    }

#ifdef D_INPUT
    printArray( connections );
#endif


    /*-----------------------------------------------------------------------------
     *  See debug.h for choosing algorithm to run!!
     *-----------------------------------------------------------------------------*/
     vector<int> solution;
     vector<int> solution2;
#ifdef  EXHASTIVE
    solution = exhastive( connections );

    printVector( solution );
    cout << calculatePathCost( connections, solution ) << endl;
#endif

#ifdef MATT
    solution = stech( connections );

    printVector(solution);
    cout << calculatePathCost(connections, solution) << endl;
#endif

#ifdef ANDREW
    solution = andrew( connections );
    if ( solution.size() != connections.size() ) {
        cout << "Not Valid!" << endl;
    }

    printVector(solution);
    cout << calculatePathCost(connections, solution) << endl;
#endif

#ifdef BOTH
    solution = stech( connections );
    solution2 = andrew( connections );
    if ( solution.size() != connections.size() || calculatePathCost( connections, solution) > calculatePathCost( connections, solution2) ) {
        printVector(solution2);
        cout << calculatePathCost( connections, solution2 ) << endl;
    } else {
        printVector(solution);
        cout << calculatePathCost(connections, solution) << endl;
    }
#endif


}

