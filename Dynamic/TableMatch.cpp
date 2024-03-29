#include "TableMatch.h"

Subsequence::Subsequence( Subsequence* toMakeBigger, size_t first, size_t last)
    : first(first), last(last), zergling(toMakeBigger) {

        size_t newSize = 2;

        if ( first == last ) {
           newSize = 1; 
        }

        if ( this->zergling == NULL ) {
            this->sequenceSize = newSize;
        } else {
            this->sequenceSize = toMakeBigger->sequenceSize + newSize;
        }
}

bool Subsequence::operator > ( const Subsequence& lhs )  const {
    return this->sequenceSize > lhs.getSize();
}

bool Subsequence::operator = ( const Subsequence& lhs )  const {
    return this->sequenceSize == lhs.getSize();
}
bool Subsequence::operator < ( const Subsequence& lhs )  const {
    return this->sequenceSize < lhs.getSize();
}

std::ostream& operator << ( std::ostream& out, const Subsequence& rhs ) {
    out << "Indices: (" << rhs.getFirstIndex() << ", " << rhs.getLastIndex() 
        << ") with size: " << rhs.getSize() << " ";
    return out;
}

std::string TableMatch::findMax() {
    this->generateEmptyTable();
    this->findMatches();
    this->addObvious();
    for ( unsigned int i = this->original.size(); i != 0; --i ) {
        this->processRow( i - 1 );
    }

    this->generateString();

    return this->largestSubsequence;
}

void TableMatch::generateEmptyTable() {
    table.resize( this->original.length());

    for ( unsigned int i = 0; i < table.size(); ++i ) {
        table[i].resize( this->original.length(), 0 );
    }

    this->putOnesInDiagonal();

}

void TableMatch::findMatches() {
    for ( unsigned int i = 0; i< table.size(); ++i ) {
        for (unsigned int j = i + 1; j < table[i].size(); ++j ){
            if ( original[i] == original[j] ) {
                table[i][j] = 1;
            }
        }
    }
}

void TableMatch::processRow( unsigned int row) {
        for ( unsigned int j = row + 1; j < table[row].size(); ++j ) {
            // if there is a match generate a pair
            if ( table[row][j] == 1 ) {
                Subsequence* newSeq;
                Subsequence* zergling = this->getLargestZergling(row, j);
                newSeq = new Subsequence( zergling, row, j );

                // add to the seqObects
                this->subOjects.push_back( newSeq );
            }
        }
}

void TableMatch::printTable() const {
    std::cout << "  ";

    for( unsigned int i = 0; i < table.size(); ++i) {
        std::cout  << original[i] << " ";
    }

    std::cout << std::endl;


    for(unsigned int i=0; i < table.size(); ++i) {
        std::cout << original[i] << " ";

        for(unsigned int j=0; j < table[i].size(); ++j) {
            std::cout << table[i][j] << " ";
        }

        std::cout << std::endl;
    }
}


void TableMatch::putOnesInDiagonal() {
    for ( unsigned int i = 0; i < table.size() && i< table[i].size(); ++i ) {
        table[i][i] = 1;
    }
}


Subsequence* TableMatch::getLargestZergling( size_t first, size_t last ) {
    // get the largest that fits within the scope
    size_t max = 0;
    Subsequence* temp = NULL;

    for ( unsigned int i = 0; i< this->subOjects.size(); ++i ){
        if ( subOjects[i]->getFirstIndex() > first && subOjects[i]->getLastIndex() < last ) {
            if ( subOjects[i]->getSize() > max ) {
                max = subOjects[i]->getSize();
                temp = subOjects[i];
            }
        }
    }

    return temp;
}

TableMatch::~TableMatch() {
    for ( unsigned int i = 0; i< subOjects.size(); ++i ) {
        delete subOjects[i];
    }
}

void TableMatch::printSequences() const {
    for ( unsigned int i = 0; i< subOjects.size(); ++i ) {
        std::cout << *subOjects[i] << std::endl;
    }
}

Subsequence* TableMatch::getLargestZergling() {

    size_t max = 0;
    Subsequence* temp = NULL;

    for ( unsigned int i = 0; i< this->subOjects.size(); ++i ){
        if ( subOjects[i]->getSize() > max ) {
            max = subOjects[i]->getSize();
            temp = subOjects[i];
        }
    }

    return temp;
}

void TableMatch::generateString() {
    Subsequence* follow = this->getLargestZergling();
    std::string temp = this->followDown( follow );

    this->largestSubsequence = temp;

}

std::string TableMatch::followDown( Subsequence* follow ) const {
    if  ( follow->zergling == NULL ) {

        std::string toReturn;

        if ( follow->sequenceSize == 2 ) {
            toReturn.push_back(this->original[follow->first]);
            toReturn.push_back(this->original[follow->last]);
        } else {
            // sequence size must be 1 and first and last are the same index
            // use only one of them
            toReturn.push_back(this->original[follow->first]);
        }

        return toReturn;

    } else {
        return this->original[follow->first] + followDown( follow->zergling) + this->original[follow->last];
    }
}

void TableMatch::addObvious() {
    for ( unsigned int i = 0; i < this->original.size(); ++i ) {
        Subsequence* single = new Subsequence( NULL, i, i);
        this->subOjects.push_back( single );
    }
}
