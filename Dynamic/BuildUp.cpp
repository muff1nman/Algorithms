#include "BuildUp.h"

void BuildUp::initArray() {
	//making the table the dimensions of the string
	//top level vector, a vector for each row
	table.resize(original.size());
	
	//we want to resize the vector for each row in the table
	for (unsigned int i = 0; i < original.size(); ++i) {
		//resize each of the vectors
		table[i].resize( original.size() );
	}
}

void BuildUp::populateDiagonal() {
	//we want the parent to be the basecase
	//not pointing to anything, therefore null
	for (unsigned int i = 0; i < original.size(); ++i) {
		table[i][i] = PalStruct(ParentType::BASECASE, 1);
	}
}

bool BuildUp::hasNextCell() {
 	//as long as incrment both col and row does not put you out of row
	//continue hasNextCell
	if (currentCell.row  == (int) original.size()) {
		return false;
	} else if (currentCell.col == (int) original.size()){ 
		return false;
	} else {
		return true;
	}

}

bool BuildUp::hasNextDiagonal() {
	//size_t currentDiagonal
	//as long as the size != original.size()
	return (currentDiagonal != original.size());
}

void BuildUp::incrementCell() {
	//increment hasNextCell
	++currentCell.row;
	++currentCell.col;
}

void BuildUp::incrementDiagonal() {
	//incrementing hasNextDiagonal
	++currentDiagonal;

    // change the current cell to be the first in the diagonal (i.e. at row 0)
    currentCell = Coord( 0, currentDiagonal );
}

void BuildUp::calcCell() {
    if ( charactersMatch() ) {
        // set to point to Diagonal
        setCurrent( ParentType::DIAGONAL );
    } else {
        if ( getAdjacent( ParentType::LEFT ) > getAdjacent( ParentType::DOWN ) ) {
            // set to point to left
            setCurrent( ParentType::LEFT );
        } else {
            // set to point to down
            setCurrent( ParentType::DOWN );
        }
    }
}

bool BuildUp::charactersMatch() {
    // check the character at row and character at col
    return original[currentCell.row] == original[currentCell.col];
}

PalStruct BuildUp::getAdjacent( ParentType::Parent parent ) {
    int row = this->currentCell.row;
    int col = this->currentCell.col;

    // pretty self explanatory here.  Just remember that diagonal is down and to
    // the left
    if ( parent == ParentType::DIAGONAL ) {
        row += 1;
        col += -1;
    } else if ( parent == ParentType::DOWN ) {
        row += 1;
    } else if ( parent == ParentType::LEFT ) {
        col += -1;
    }

    return table[row][col];
}

void BuildUp::setCurrent( ParentType::Parent parent ) {
   table[this->currentCell.row][this->currentCell.col].parent = parent;

   table[this->currentCell.row][this->currentCell.col].maxPalSeqSize =
       this->getAdjacent(parent).maxPalSeqSize;

   // only if the parent type is diagonal then increase the maximum palindrome
   // length
   if ( parent == ParentType::DIAGONAL ) {
       table[this->currentCell.row][this->currentCell.col].maxPalSeqSize += 2;
   }
}

std::string BuildUp::getPalindromeSubsequence () {

    // start at the top right
    return this->recursiveTraceback( Coord( 0, original.size() - 1 ) );
}

std::string BuildUp::recursiveTraceback( Coord current ) {

    std::string empty;
    if ( table[current.row][current.col].parent == ParentType::BASECASE ) {
        // catch the base case along the main diagonal
        if ( current.row == current.col ) {
            // single character
            empty.push_back( original[current.row] ) ;
        } 
        // otherwise return an empty string because the other base case has
        // already been covered by the diagonal.

        return empty;
    }

    if ( table[current.row][current.col].parent == ParentType::DIAGONAL ) {
        return original[ current.row ] + recursiveTraceback( current + Coord(1,-1) ) + original[ current.col ];
    }


    if ( table[current.row][current.col].parent == ParentType::LEFT ) {
        return recursiveTraceback( current + Coord(0,-1) );
    }
    if ( table[current.row][current.col].parent == ParentType::DOWN ) {
        return recursiveTraceback( current + Coord(1,0) );
    }

    std::cout << "We got problems" << std::endl;

    return "";

}

void BuildUp::printTable() {
    for ( unsigned int i = 0; i< table.size(); ++i ) {
        for ( unsigned int j = 0; j < table[i].size(); ++j ) {

            if ( table[i][j].parent == ParentType::BASECASE ) {
                std::cout << "B";
            }
            if ( table[i][j].parent == ParentType::DIAGONAL ) {
                std::cout << "D";
            }
            if ( table[i][j].parent == ParentType::LEFT ) {
                std::cout << "L";
            }
            if ( table[i][j].parent == ParentType::DOWN ) {
                std::cout << "W";
            }
        }
        std::cout << std::endl;
    }
}
