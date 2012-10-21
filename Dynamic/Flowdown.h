/*
 * =====================================================================================
 *
 *       Filename:  Flowdown.h
 *
 *    Description:  A dynamic programming attempt using a flow down approach to
 *                  calculate the maximum palindrome length.  See the
 *                  explanation below
 *
 * 
 * Consider the string "gama"
 *
 * Create a table with the word along each axis with the diagonal
 * initialized to one.
 *
 *   g a m a
 *   g 1 _ _ _
 *   a _ 1 _ _
 *   m _ _ 1 _
 *   a _ _ _ 1
 *
 * The horizontal axis resembles the starting character and the vertical
 * axis represents the last character.  The number at the corresponding
 * string is the maximum length of a palindrome found in the range from
 * the starting character to the last character.  The diagonal has to
 * been initialized to one as the base case considering a character by
 * itself is a palindrome of length one. 
 *
 * Ignoring the top right triangular half (those cells represent
 * reversed strings) we iterate through each column (starting character)
 * and then downwards populating each cell.  Each cell is calculated
 * with the following logic:
 *
 * If the entire substring from starting character to ending character
 * is a palindrome, the cell value is equal to the length of this
 * substring, otherwise, the value is equal to the cell above it. 
 *
 * Here is an example column calculation using column 2:
 *
 *   g a m a
 *   g 1 _ _ _
 *   a _ 1 _ _
 *   m _ x 1 _
 *   a _ _ _ 1
 *
 * First consider the cell with an "x", the substring at this point
 * starts at the first "a" and goes to "m" i.e. "am".  This is not a
 * palindrome, so we copy the value above:
 *
 *   g a m a
 *   g 1 _ _ _
 *   a _ 1 _ _
 *   m _ 1 1 _
 *   a _ X _ 1
 *
 * Now we consider the next entry.  This substring is "ama" which is
 * palindrome so we replace the cell with the length which is 3. 
 *
 *   g a m a
 *   g 1 _ _ _
 *   a _ 1 _ _
 *   m _ 1 1 _
 *   a _ 3 _ 1
 *
 * A fully populated table looks like this:
 *
 *   g a m a
 *   g 1 1 1 1
 *   a 1 1 1 1
 *   m 1 1 1 1
 *   a 1 3 1 1
 *
 * Now the maximum palindrome is found by finding the maximum value
 * along the bottom row and then proceding up the column while the value
 * stays the same. (NOTE there are ones in the upper right triangle but
 * this is largely irrelevant and does not affect the correctness of the
 * algorithm.
 *
 * For an example of a bigger word:
 *   A C G T T C T A A A A T C G
 *   A 1 1 1 1 1 1 1 1 1 1 1 1 1 1
 *   C 1 1 1 1 1 1 1 1 1 1 1 1 1 1
 *   G 1 1 1 1 1 1 1 1 1 1 1 1 1 1
 *   T 1 1 1 1 1 1 1 1 1 1 1 1 1 1
 *   T 1 1 1 2 1 1 1 1 1 1 1 1 1 1
 *   C 1 1 1 2 1 1 1 1 1 1 1 1 1 1
 *   T 1 1 1 2 3 1 1 1 1 1 1 1 1 1
 *   A 1 1 1 2 3 1 1 1 1 1 1 1 1 1
 *   A 1 1 1 2 3 1 1 2 1 1 1 1 1 1
 *   A 1 1 1 2 3 1 1 3 2 1 1 1 1 1
 *   A 1 1 1 2 3 1 1 4 3 2 1 1 1 1
 *   T 1 1 1 2 3 1 6 4 3 2 1 1 1 1
 *   C 1 1 1 2 3 8 6 4 3 2 1 1 1 1 <-------
 *   G 1 1 1 2 3 8 6 4 3 2 1 1 1 1
 *                         ^               
 *                         |
 *                         |
 *
 *  So it can be seen that the largest is 8 in length and starts at the
 *  second "C" and ends at the last "C".   
 *
 *        Version:  1.0
 *        Created:  10/20/2012 12:52:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew DeMaria, ademaria@mines.edu
 *                  Tri Nguyen, tringuye@mines.edu
 *                  Maria Deslis, mdeslis@mines.edu
 *   Organization:  Colorado School of Mines
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include "Palindrome.h"

#pragma once

class Flowdown {

    public:
        // durin the constructor the table is populate to hold the values needed
        // by calcMaximum.
        Flowdown(std::string palindrome);

        // return the largest substring that is a palindrome.  DO NOT call
        // before calling calcMaximum
        std::string getMaximum();

        // Calling this function traverses the table to find the largest
        // palindrome
        void calcMaximum();

        // prints the table used during the calcMaximum step.  May be called
        // before calcMaximum if desired.
        void printTable();

    private:
        std::string initdrome;

        std::vector<std::vector<int> > table;

        // This is called by the constructor to populate the table with the
        // values needed by calcMaximum.
        void populateTable();

        // resize the table according to the size of initdrome
        void reserveTable();
        
        // the largest substring that is a palindrome
        std::string actPalindrome;
};

