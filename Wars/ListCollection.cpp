#include "ListCollection.h"


ListCollection::ListCollection( const std::vector<int>& initialVertices , const ConnMatrix& connections ) : connections(connections) {
    std::vector<int>* newList;
    for ( int i = 0; i < initialVertices.size(); ++i ) {
        // create new list
        newList = new std::vector<int>();
        newList->push_back( initialVertices[i] );
        mapping[ initialVertices[i] ] = newList;
    }
}

void ListCollection::joinList( int v1, int v2 ) {

    // get the lists for v1 and v2
    list forv1 = mapping[v1];
    list forv2 = mapping[v2];

    // first test whether v1 and v2 are already in the same list ---
    // do nothing
    if ( forv1 == forv2 ) {
        return;
    }

    // new list
    list newList;
    list current = new std::vector<int>();


    // make sure the size is good
    current->resize( forv1->size() + forv2->size() );
    
    // try as is
    std::copy( forv1->begin(), forv1->end(), current->begin());
    std::copy_backward( forv2->begin(), forv2->end(), current->end());

    // set as best
    newList = current;
    int bestCost = calculatePathCost( connections, *current) ;

    // test more
    // TODO


    // delete the old lists
    delete forv1;
    delete forv2;

    // now fix map
    this->fixMap( newList );

}

bool ListCollection::isDone( ) {
    // TODO
    return true;
}


const std::vector<int>& ListCollection::getVector( ) {
    std::vector<int> theList;
    // TODO

    return theList;
}


void ListCollection::fixMap( list newList) {
    for ( std::vector<int>::iterator i = newList->begin(); i != newList->end(); ++i ) {
        mapping[*i] = newList;
    }
}
