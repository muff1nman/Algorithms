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
#include <queue>

using namespace std;

class ModuleConnection {
  public:
    ModuleConnection(int v1, int v2, int w) :
      vertex1(v1),
      vertex2(v2),
      weight(w) {}

    int getWeight() const { return weight; }
    int getVertexOne() const { return vertex1; }
    int getVertexTwo() const { return vertex2; }

    bool operator<(const ModuleConnection& other) const { return weight < other.getWeight(); }
  private:
    int vertex1;
    int vertex2;
    int weight;

};

bool shouldAddToStart(int listSize, int index, int weight);

void stech(ConnMatrix connections) {
  cout << "BEGINNING STECH ALGORITHM\n";
  vector<ModuleConnection> edges;

  int size = connections.size();
  for (int i = 0; i < size; ++i) {
    for (int j = i; j < size; ++j) {
      int weight = connections.at(i).at(j);
      if (weight > 0) {
        ModuleConnection c(i, j, weight);
        edges.push_back(c);
      }
    }
  }

  sort( edges.rbegin(), edges.rend() );
  size = edges.size(); 
#ifdef D_MATT
  for (int i = 0; i < edges.size(); ++i)
    cout << "Edge " << i << ": " << edges.at(i).getWeight() << endl;
#endif

  vector<int> result;
  queue<ModuleConnection> ignore;

  bool dataLoc[size];
  for (int i = 0; i < size; ++i)
    dataLoc[i] = false;

  int emptySlots = size;
  for (int i = 0; i < size; ++i) {
    ModuleConnection mc = edges.at(i);

#ifdef D_MATT
    cout << "Got edge " << i << ": " << mc.getWeight() << endl;
#endif
    const int v1 = mc.getVertexOne();
    const int v2 = mc.getVertexTwo();
    int weight = mc.getWeight();

    if (emptySlots == size) {
      //add the two right away
      result.push_back(v1);
      result.push_back(v2);

      dataLoc[v1] = dataLoc[v2] = true;
      emptySlots -= 2;

      cout << "Adding: " << v1 << " - " << v2 << endl;
    } else if (dataLoc[v1] == false && dataLoc[v2] == true) {
      //v1 not in result yet, v2 does exist, add v1
      //find the index of v2
      int index;
      for (int j = 0; j < result.size(); j++) {
        if (result.at(j) == v2)
          index = j;
      }
      //minimize distance by checking whether to add at the front or end
      if (shouldAddToStart(size, index, weight)) {
        result.insert(result.begin(), v1);
      } else {
        result.insert(result.end(), v1);
      }
      dataLoc[v1] = true;
      emptySlots--;
      cout << "Adding " << v1 << endl;
    } else if (dataLoc[v1] == true && dataLoc[v2] == false) {
      //v2 not in result yet, v1 does, add v2
      int index;

      for (int j = 0; j < result.size(); j++) {
        if (result.at(j) == v1)
          index = j;
      }

      if (shouldAddToStart(size, index, weight)) {
        result.insert(result.begin(), v2);
      } else {
        result.insert(result.end(), v2);
      }
      dataLoc[v2] = true;
      emptySlots--;
      cout << "Adding " << v2 << endl;
    } else {
      ignore.push(mc);
      cout << "Adding to ignore list\n";
    }
  }

  for (int i = 0; i < result.size(); ++i)
    cout << result.at(i) << " \n";
}


bool shouldAddToStart(int listSize, int index, int weight) {
  return (index * weight) < ((listSize - index) * weight);
}
