/*
 * =====================================================================================
 *
 *       Filename:  Center.h
 *
 *    Description:  This contains an alorithm to find the largest subsequence of
 *                  a string that is also a palindrome. 
 *
 *                  The idea is that every possible palindrome subsequence has a
 *                  center.  The center is either a null character between two
 *                  characters or an actual character.  For each of these
 *                  centers find the maximum palindrome subsequence using that
 *                  character as the center.  Then the largest max is the
 *                  largest subsequence.  
 *
 *        Version:  1.0
 *        Created:  10/22/2012 10:55:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew DeMaria , ademaria@mines.edu
 *                  Tri Nguyen, tringuye@mines.edu
 *                  Maria Deslis, mdeslis@mines.edu
 *   Organization:  Colorado School of Mines
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <string>

class Center {
    public:
        // ctor
        Center( const std::string& original ) : original(original) { }

        // wraps up all the dirty work into one step
        std::string findMax();

        // generates an empty table except with the diagonal as 1's
        void generateEmptyTable();

        // populates the table with 1's at the intersections of matching
        // characters.  Only uses the upper right half of the table
        void findMatches();

        // adds indice, value, parent pairs to the given container.
        void processRow();

    private:
        std::string original;
        std::string largestSubsequence;

};
