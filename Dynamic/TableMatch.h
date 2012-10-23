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
#include <iostream>                             /* For debugging only */

class Subsequence {
    public :
        Subsequence( Subsequence* toMakeBigger, size_t first, size_t last);

        size_t getFirstIndex() const { return this->first; }

        size_t getLastIndex() const { return this->last; }

        size_t getSize() const { return this->sequenceSize; }

        // comparison operators
        bool operator > ( const Subsequence& lhs ) const ;
        bool operator = ( const Subsequence& lhs ) const ;
        bool operator < ( const Subsequence& lhs ) const ;

        // for debugging
        friend std::ostream& operator << ( std::ostream& out, const Subsequence& rhs);

        friend class TableMatch;

    private:
        size_t first, last;
        Subsequence* zergling;
        size_t sequenceSize;
};

std::ostream& operator << ( std::ostream& out, const Subsequence& rhs);

class TableMatch {
    public:
        // ctor
        TableMatch( const std::string& original ) : original(original) { }

        // dtor
        ~TableMatch();

        // wraps up all the dirty work into one step
        std::string findMax();

        // for debugging
        void printTable() const ;

        // for debugging
        void printSequences() const ;

    private:
        std::string original;
        std::string largestSubsequence;
        std::vector<Subsequence*> subOjects;
        std::vector< std::vector< size_t > > table;


        /*-----------------------------------------------------------------------------
         *  Helper functions
         *-----------------------------------------------------------------------------*/

        void putOnesInDiagonal();

        // returns the largest Subsequence that fits BETWEEN (non inclusive)
        // these indices
        Subsequence* getLargestZergling( size_t first, size_t last );

        // find the Subsequence with the largest size
        Subsequence* getLargestZergling();

        std::string followDown( Subsequence* follow ) const ;

        // generates the string by jumping back through all the Subsequences
        void generateString();

        // generates an empty table except with the diagonal as 1's
        void generateEmptyTable();

        // populates the table with 1's at the intersections of matching
        // characters.  Only uses the upper right half of the table
        void findMatches();

        // adds indice, value, parent pairs to the given container.
        void processRow( unsigned int row );

};
