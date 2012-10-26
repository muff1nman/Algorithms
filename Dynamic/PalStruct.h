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

#include <cstdlib>

struct Coord {
    size_t row,col;
};

// encapsulate with a namespace to prevent collisions
namespace ParentType {
    enum Parent {
        LEFT, DIAGONAL, DOWN,
    };
}

struct PalStruct {
    Coord self;

    Parent parent;

    size_t maxPalSeqSize;

};
