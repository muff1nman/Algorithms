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
        // TODO
        // set to point to Diagonal
    } else {
        if ( getAdjacent( ParentType::LEFT ) > getAdjacent( ParentType::DOWN ) ) {
            // set to point to left
            // TODO
        } else {
            // set to point to down
            // TODO
        }
    }


}

bool BuildUp::charactersMatch() {
    // TODO
    return false;
}

PalStruct BuildUp::getAdjacent( ParentType::Parent type ) {
    // TODO
    return table[0][0];
}
