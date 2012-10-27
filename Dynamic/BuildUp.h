/*
 * =====================================================================================
 *
 *       Filename:  BuildUp.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/26/2012 01:33:53 PM
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
#include "PalStruct.h"
#include <string>
#include <vector>

class BuildUp {

    BuildUp( std::string original ) : original(original) {}

    private:
        std::string original;
        std::vector< std::vector<PalStruct> > table;
	// row and column struct
	// 
        Coord currentCell;
        size_t currentDiagonal;

        // resize the array to size of original (allows for string x string table)
        void initArray();

        // Populate the diagonal with single character PalStructs
	// base case
        void populateDiagonal();

        // returns false if a call to increment cell would push this out of
        // bounds
        bool hasNextCell();

        // returns false if a call to increment diagonal would push this out of
        // bounds
        bool hasNextDiagonal();

        // increments the cell down the diagonal
        void incrementCell();
       
	// once there are no more cells for incrementCell()
        // increments the diagonal to the upper right
        void incrementDiagonal();

        // calculates the current PalStruct based on the recursive relationship
        // that is in the rest of the array
	// does the comparisons between indices
        void calcCell();

        // returns whether the character represented by the currentCell are
        // matching
        bool charactersMatch();

        // get the adjacent PalStruct based on the supplied parent direction
        PalStruct getAdjacent( ParentType::Parent parent );

        // set the current PalStruct using the supplied parent as the parent
        void setCurrent( ParentType::Parent parent );
};
