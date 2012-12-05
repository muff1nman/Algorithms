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

using namespace std;

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
  cout << "BEGINNING STECH ALGORITHM\n";
  vector<ModuleConnection> edges;
  
  int size = connections.size();
  cout << "Size: " << size << endl;
  for (int i = 0; i < size; ++i) {
    for (int j = i; j < size; ++j) {
      int weight = connections.at(i).at(j);
      if (weight > 0) {
        ModuleConnection c(i, j, weight);
        edges.push_back(c);
      }
    }
  }
  
  sort( edges.begin(), edges.end() );
 
#ifdef
  for (int i = 0; i < edges.size(); ++i)
    cout << "Edge " << i << ": " << edges.at(i).getWeight() << endl;
#endif
}


