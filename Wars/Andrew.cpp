#include "Andrew.h"

std::vector<int> andrew( const ConnMatrix& connections ) {
    std::vector<ModuleConnection> edges;
    populateEdges(connections, edges );

}

void populateEdges( const ConnMatrix& connections, std::vector<ModuleConnection>& edges ) {
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
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
