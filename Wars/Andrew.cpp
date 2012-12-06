#include "Andrew.h"

std::vector<int> andrew( const ConnMatrix& connections ) {
    std::vector<ModuleConnection> edges;
    std::vector<int> initial( connections.size() );
    insertOrdered(initial);
    ListCollection list( initial, connections );

    populateEdges(connections, edges );

    while( !edges.empty() ) {
        list.joinList( edges.front().getVertexOne(), edges.front().getVertexTwo() );
        edges.erase( edges.begin() );
    }

    return list.getVector();
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
