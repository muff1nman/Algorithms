/*
 * =====================================================================================
 *
 *       Filename:  TableMatch.h
 *
 *    Description:  This contains an alorithm to find the largest subsequence of
 *                  a string that is also a palindrome. 
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
#include <set>
#include <vector>

class Subsequence {
    public :
        Subsequence( Subsequence* toMakeBigger, size_t first, size_t last);

        size_t getFirstIndex() const { return this->first; }

        size_t getLastIndex() const { return this->last; }

        size_t getSize() const { return this->sequenceSize; }

        // comparison operators
        bool operator > ( const Subsequence& lhs );
        bool operator = ( const Subsequence& lhs );
        bool operator < ( const Subsequence& lhs );

    private:
        size_t first, last;
        Subsequence* zergling;
        size_t sequenceSize;
};

class TableMatch {
    public:
        // ctor
        TableMatch( const std::string& original ) : original(original) { }

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
        std::multiset<Subsequence> subOjects;
        std::vector< std::vector< size_t > > table;

};
