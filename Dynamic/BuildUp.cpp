#include "BuildUp.h"

void BuildUp::initArray() {
    // TODO
}

void BuildUp::populateDiagonal() {
    // TODO
}

bool BuildUp::hasNextCell() {
    // TODO
    return false;
}

bool BuildUp::hasNextDiagonal() {
    // TODO
    return false;
}

void BuildUp::incrementCell() {
    // TODO
}

void BuildUp::incrementDiagonal() {
    // TODO
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
