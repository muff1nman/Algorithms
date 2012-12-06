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
 *                  Matt Stech (mstech), mstech@mines.edu
 *                  Aakash Shah (aashah), ashah@mines.edu
 *                  Josh Wretlind (joshWretlind), jwretlin@mines.edu
 *   Organization:  Colorado School of Mines
 *
 * =====================================================================================
 */
#ifndef HELPER_H
#define HELPER_H
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include "ConnMatrix.h"
#include "debug.h"
#include <climits>

// calculate the absolute distance between two unique componets in a // array.  (i.e. if they are adjacent, return 1.  If there is a
// component between them return 2 )
// IF the components don't exisit return -1
int distance(const std::vector<int>& path, int one, int two );

// calculates the cost of a given path using the supplied connection
// matrix. The connection matrix is indexed base 0 so there are
// components 0 to (n - 1)
int calculatePathCost(const ConnMatrix& connections, const std::vector<int>& path );

void printVector( const std::vector<int>& toPrint );

#endif
