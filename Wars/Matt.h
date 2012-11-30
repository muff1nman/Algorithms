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


class ModuleConnection {
  public:
    ModuleConnection(int v1, int v2, int w) :
      vertex1(v1),
      vertex2(v2),
      weight(w) {}
    
    bool operator<(const ModuleConnection& other) { return weight < other.weight; }

    int vertex1;
    int vertex2;
    int weight;
    
};
std::vector<int> stech(ConnMatrix connections) {
  vector<ModuleConnection> edges;

  for (int i = 0; i < connections.size(); ++i) {
    for (int j = i; j < connections.at(i).size(); ++i) {
      ModuleConnection c(i, j, connections.at(i).at(j));
      edges.push_back(c);
    }
  }

  std::sort( edges.begin(), edges.end() );

  for (int i = 0; i < edges.size(); ++i)
    cout << "Edge " << i << ": " << edges.at(i) << endl;
}


