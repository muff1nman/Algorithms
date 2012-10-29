/*
 * =====================================================================================
 *
 *       Filename:  PalStruct.h
 *
 *    Description:  A simple structure that holds a reference to the parent
 *                  PalStruct along with indices of the cell that it is stored
 *                  at.  Also, it will store the maximum palindrome subsequence
 *                  that it has.
 *
 *        Version:  1.0
 *        Created:  10/26/2012 01:19:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew DeMaria (muff1nman), ademaria@mines.edu
 *                  Tri Nguyen, tringuye@mines.edu
 *                  Maria Deslis, mdeslis@mines.edu
 *   Organization:  Colorado School of Mines
 *
 * =====================================================================================
 */

#ifndef PALSTRUCT_H
#define PALSTRUCT_H

#include <cstdlib>
#include <iostream>

// a simple (x,y) or (row,col) coordinate
struct Coord {
    int row,col;

    Coord( ) : row(0), col(0) {}

    Coord( int  row, int col) : row(row), col(col) {}

    Coord operator + (const Coord& other ) {
        Coord toReturn;
        toReturn.row = this->row + other.row;
        toReturn.col = this->col + other.col;
        return toReturn;
    }
};

// encapsulate with a namespace to prevent collisions
namespace ParentType {
    // choose cell
    enum Parent {
        LEFT, DIAGONAL, DOWN, BASECASE
    };
}

// Holds a reference and a size
struct PalStruct {
    ParentType::Parent parent;

    size_t maxPalSeqSize;

    PalStruct( ) : parent( ParentType::BASECASE ), maxPalSeqSize( 0 ) {}

    PalStruct( ParentType::Parent parent, size_t maxPalSeqSize ) :
        parent(parent), maxPalSeqSize( maxPalSeqSize ) {}

    bool operator < ( const PalStruct& other ) const {
        return this->maxPalSeqSize < other.maxPalSeqSize;
    }

    bool operator > ( const PalStruct& other ) const {
        return this->maxPalSeqSize > other.maxPalSeqSize;
    }

    bool operator == ( const PalStruct& other ) const {
        return this->maxPalSeqSize == other.maxPalSeqSize;
    }

};


#endif
