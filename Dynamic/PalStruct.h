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


struct Coord {
    int row,col;

    Coord( ) : row(0), col(0) {}

    Coord( int  row, int col) : row(row), col(col) {}

    Coord operator + (const Coord& other ) {
        Coord toReturn;
        toReturn.row = this->row + other.row;
        toReturn.col = this->col + other.col;
//        std::cout << "other row: " << other.row << " this row: " << this->row << std::endl;
//        std::cout << "row: " << toReturn.row << " col: " << toReturn.col << std::endl;
        return toReturn;
    }
};

// encapsulate with a namespace to prevent collisions
namespace ParentType {
    enum Parent {
        LEFT, DIAGONAL, DOWN, BASECASE
    };
}

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

    //friend std::ostream& operator << ( std::ostream& out, const PalStruct& toPrint ) ;

};


//std::ostream& operator << ( std::ostream& out, const PalStruct& toPrint ) {
//    if ( toPrint.parent == ParentType::BASECASE ) {
//        out << "B";
//    }
//    if ( toPrint.parent == ParentType::DIAGONAL ) {
//        out << "D";
//    }
//    if ( toPrint.parent == ParentType::LEFT ) {
//        out << "L";
//    }
//    if ( toPrint.parent == ParentType::DOWN ) {
//        out << "W";
//    }
//}

#endif
