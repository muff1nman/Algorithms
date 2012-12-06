#include "Andrew.h"

std::vector<int> andrew( const ConnMatrix& connections ) {
    std::vector<ModuleConnection> edges;
    std::vector<int> toReturn( connections.size() );

#ifdef D_ANDREW
    insertOrdered(toReturn);
#endif

    populateEdges(connections, edges );

    return toReturn;
}

void populateEdges( const ConnMatrix& connections, std::vector<ModuleConnection>& edges ) {
    for (int i = 0; i < connections.size(); ++i) {
        for (int j = i; j < connections.size(); ++j) {
            int weight = connections.at(i).at(j);
            if (weight > 0) {
                ModuleConnection c(i, j, weight);
                edges.push_back(c);
            }
        }
    }

    // sort all the connections
    sort( edges.rbegin(), edges.rend() );

}

void insertOrdered( std::vector<int>& array ) {
    for ( int i = 0; i < array.size(); ++i ) {
        array[i] = i;
    }
}
