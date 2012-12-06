/*
 * =====================================================================================
 *
 *       Filename:  Matt.h
 *
 *    Description:  A greedy algorithm made by Matthew Stech Ph.d
 *                  
 *
 *                  How Andrew understands it:
 *
 *                  method main() :
 *
 *                      Order the edges by the number of connections,
 *                      hightest to lowest called C
 *    
 *                      instatiate a collection of lists called Q
 *
 *                      put each vertix into its own list in Q
 *    
 *                      while Q does not have a list with n vertices
 *                          remove top edge from C
 *                          call join on list with vertex C.v1 and on
 *                          list with vertex C.v2
 *                          
 *    
 *                      done
 *
 *                  method joinlist( L1, L2 ):
 *                      // vertex1 is the first vertex that was used
 *                      to grab L1 while vertex2 is the same for L2
 *                      if ( both vertex1 and vertex2 are on a
 *                      boundary in their perspective lists ):
 *                          flip L1 so that vertex1 is on the back
 *                          flip L2 so that vertex2 is on the front
 *                          NewList = L1 + L2
 *                      else:
 *                          NewList = L1 and L2
 *
 *
 *        Version:  1.0
 *        Created:  11/30/2012 11:23:00am MTC
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

#pragma once

#include <vector>
#include <cstdlib>
#include "debug.h"
#include "ConnMatrix.h"
#include "Helper.h"
#include <vector>
#include "ModuleConnection.h"

std::vector<int> andrew(const ConnMatrix& connections );

// populate edges with nonzero connections
void populateEdges( const ConnMatrix& connections, std::vector<ModuleConnection>& edges );

// just a function for testing
void insertOrdered( std::vector<int>& array );

