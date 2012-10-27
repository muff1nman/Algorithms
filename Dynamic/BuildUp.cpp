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
    // TODO
    return false;
}

PalStruct BuildUp::getAdjacent( ParentType::Parent parent ) {
    // TODO
    size_t row = this->currentCell.row;
    size_t col = this->currentCell.col;

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

   // only if the parenttype is diagonal then increase the maximum palindrome
   // length
   if ( parent == ParentType::DIAGONAL ) {
       table[this->currentCell.row][this->currentCell.col].maxPalSeqSize += 2;
   }
}
