#include "TableMatch.h"

Subsequence::Subsequence( Subsequence* toMakeBigger, size_t first, size_t last)
    : first(first), last(last), zergling(toMakeBigger) {

        if ( this->zergling == NULL ) {
            this->sequenceSize = 2;
        } else {
            this->sequenceSize = toMakeBigger->sequenceSize + 2;
        }

}

bool Subsequence::operator > ( const Subsequence& lhs ) {
    return this->sequenceSize > lhs.getSize();
}

bool Subsequence::operator = ( const Subsequence& lhs ) {
    return this->sequenceSize == lhs.getSize();
}
bool Subsequence::operator < ( const Subsequence& lhs ) {
    return this->sequenceSize < lhs.getSize();
}

std::string TableMatch::findMax() {
    // TODO
    return "";
}

void TableMatch::generateEmptyTable() {
    table.resize( this->original.length(), 0 );
    

}

void TableMatch::findMatches() {
    // TODO
}

void TableMatch::processRow() {
    // TODO
}

