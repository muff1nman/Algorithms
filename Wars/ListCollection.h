/*
 * =====================================================================================
 *
 *       Filename:  ListCollection.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/05/2012 06:28:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew DeMaria (muff1nman), ademaria@mines.edu
 *   Organization:  Colorado School of Mines
 *
 * =====================================================================================
 */

#pragma once
#include <cstdlib>
#include <map>
#include <vector>
#include "ConnMatrix.h"
#include <algorithm>
#include "Helper.h"

class ListCollection {
    public:
        typedef std::vector<int>* list;
        typedef std::map< int, list > VertexToList;
        // instantiates an initial collection where each vertex is in its
        // own group
        ListCollection( const std::vector<int>& initialVertices, const ConnMatrix& connections );

        void joinList( int v1, int v2 );

        bool isDone( );

        // return all lists joined together
        std::vector<int> getVector( );

    private:
        VertexToList mapping;
        ConnMatrix connections;

        void fixMap( list newList );
};


