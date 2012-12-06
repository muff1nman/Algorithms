#include "ListCollection.h"


ListCollection::ListCollection( const std::vector<int>& initialVertices ) {
    std::vector<int>* newList;
    for ( int i = 0; i < initialVertices.size(); ++i ) {
        // create new list
        newList = new std::vector<int>();
        newList->push_back( initialVertices[i] );
        mapping[ initialVertices[i] ] = newList;
    }
}

void ListCollection::joinList( int v1, int v2 ) {
    // TODO
}

bool ListCollection::isDone( ) {
    // TODO
    return True;
}


const std::vector<int>& ListCollection::getVector( ) {
    std::vector<int> theList;
    // TODO

    return  theList;
}
