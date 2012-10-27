#include "BuildUp.h"

void BuildUp::initArray() {
	//making the table the dimensions of the string
	//top level vector, a vector for each row
	table.resize(original.size());
	
	//we want to resize the vector for each row in the table
	for (unsigned int i = 0; i < original.size(); ++i) {
		//resize each of the vectors
		table[i].resize(original.size());
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
	if (currentCell.row + 1 == original.size()) {
		return false;
	} else if (currentCell.col + 1 == original.size()){ 
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
    return original[currentCell.row] == original[currentCell.col];
}

PalStruct BuildUp::getAdjacent( ParentType::Parent parent ) {
    size_t row = this->currentCell.row;
    size_t col = this->currentCell.col;

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
    
}

std::string BuildUp::recursiveTraceback( Coord current ) {
    if ( table[current.row][current.col].parent == ParentType::BASECASE ) {
        // two base cases... a single character and two characters
        if ( current.row == current.col ) {
            // single character
            return original[current.row];
        } else {
            // double character (the same but use row and col just for
            // correctness
            return orginal[current.row] + original[current.col];
        }
    }

    // TODO
}
