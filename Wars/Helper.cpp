#include "Helper.h"

int distance(const std::vector<int>& path, int one, int two ) {
    std::vector<int>::const_iterator one_index = std::find( path.begin(), path.end(), one);
    std::vector<int>::const_iterator two_index = std::find( path.begin(), path.end(), two);

    if ( one_index == path.end() || two_index == path.end() ) {
        return 0;
    }

    return abs( one_index - two_index );
}

int calculatePathCost(const ConnMatrix& connections, const std::vector<int>& path ) {
    int cost = 0;
    // for each pair of componets, ( i and j) add the distance *
    // number of connections between those components to the cost
    for ( unsigned int i = 0; i < connections.size(); ++i ) {
        for( unsigned int j = i + 1; j < connections[i].size(); ++j ) {
            cost += distance( path, i, j ) * connections[i][j];
        }
    }

    return cost;
}

void printVector( const std::vector<int>& toPrint ) {
    for ( unsigned int i = 0 ; i < toPrint.size(); ++i ) {
        std::cout << toPrint[i] + 1 << " ";
    }
    std::cout << std::endl;
}
