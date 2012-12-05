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
 *                  Matt Stech (mstech), mstech@mines.edu
 *                  Aakash Shah (aashah), ashah@mines.edu
 *                  Josh Wretlind (joshWretlind), jwretlin@mines.edu
 *   Organization:  Colorado School of Mines
 *
 * =====================================================================================
 */
#include <cstdlib>
#include <fstream>
#include "debug.h"
#include <utility>
#include "ConnMatrix.h"

// only needed when in debug mode
#ifdef D_INPUT
#include <iostream>
#endif

ConnMatrix import(char* filename) {
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

  if ( sizeOfN < 1 || sizeOfN > 100 ) {
      throw INVALID_GRAPH;
  }

  // create a new int array to return
  ConnMatrix connections;
  connections.resize( sizeOfN );
  for ( int i = 0; i < sizeOfN ; ++i ) {
    connections[i].resize( sizeOfN );
  }

  for( int i = 0; i < sizeOfN; ++ i ) {
    for ( int j = 0; j < sizeOfN; ++j ) {
      file >> connections[i][j];
      if ( file.bad() ) {
          throw INVALID_GRAPH;
      }
    }
  }

  return connections;
}

#ifdef D_INPUT
// print a 2d array
void printArray( ConnMatrix array ) {
  std::cout << "Array: " << std::endl;
  for (unsigned int i = 0; i < array.size(); ++i ) {

    for ( unsigned int j = 0; j < array[i].size(); ++j ) {
      std::cout << array[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "EndArray" << std::endl;
}
#endif

