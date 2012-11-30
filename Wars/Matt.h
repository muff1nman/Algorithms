/*
 * =====================================================================================
 *
 *       Filename:  Matt.h
 *
 *    Description:  A greedy algorithm made by Matthew Stech Ph.d
 *
 *        Version:  1.0
 *        Created:  11/30/2012 11:23:00am MTC
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Stech (mstech@mines.edu)
 *   Organization:  
 *
 * =====================================================================================
 */

#pragma once

#include <vector>
#include <cstdlib>
#include "debug.h"

class ModuleConnection {
    public:
        ModuleConnection(int v1, int v2, int w) :
            vertex1(v1),
            vertex2(v2),
            weight(w) {}

        int getWeight() const { return weight; }

        bool operator<(const ModuleConnection& other) const { return weight < other.getWeight(); }
    private:
        int vertex1;
        int vertex2;
        int weight;

};

void stech(ConnMatrix connections) {
    std::vector<ModuleConnection> edges;

    for (int i = 0; i < connections.size(); ++i) {
        for (int j = i; j < connections.size(); ++j) {
            ModuleConnection c(i, j, connections.at(i).at(j));
            edges.push_back(c);
        }
    }

    std::sort( edges.rbegin(), edges.rend() );
#ifdef D_MATT_edges
    for (int i = 0; i < edges.size(); ++i)
        std::cout << "Edge " << i << ": " << edges.at(i).getWeight() << std::endl;
#endif
}


