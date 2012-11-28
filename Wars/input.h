/*
 * =====================================================================================
 *
 *       Filename:  input.h
 *
 *    Description:  Imports a connectivity matrix into an n x n 2d
 *                  array of ints
 *
 *        Version:  1.0
 *        Created:  11/28/2012 12:58:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew DeMaria (muff1nman), ademaria@mines.edu
 *                  Matt Stech, mstech@mines.edu
 *                  Aakash Shah, ashah@mines.edu
 *   Organization:  Colorado School of Mines
 *
 * =====================================================================================
 */
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "debug.h"

int** import(char* filename) {
    std::fstream file;
    int sizeOfN;

    file.open( filename );
    if ( ! file ) {
        throw FILENAME_INVALID;
    }

    file >> sizeOfN;

#ifdef D_INPUT
    std::cout << "The number of components is: " << sizeOfN << std::endl;
#endif

    // create a new int array to return
    int** connections = new int*[ sizeOfN ];
    for ( int i = 0; i < sizeOfN ; ++i ) {
        connections[i] = new int[ sizeOfN ];
    }

    return connections;
    
}

