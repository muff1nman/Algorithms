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

#include "Helper.h"


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
void addToResult(vector<int>& list, int moduleToAdd, int moduleAlreadyInThere, int weight);


vector<int> stech(ConnMatrix connections) {
#ifdef D_MATT
  cout << "BEGINNING STECH ALGORITHM\n";
#endif

  vector<ModuleConnection> edges;

  int size = connections.size();
#ifdef D_MATT
   cout << "Size: " << size << endl;
#endif
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
  cout << "SIZE: " << size << endl;
  for (int i = 0; i < size; ++i)
    cout << "Edge " << i << " (v1, v2): (" << edges.at(i).getVertexOne() << ", " << edges.at(i).getVertexTwo() << ") " << edges.at(i).getWeight() << endl;
#endif

  vector<int> result;
  queue<ModuleConnection> ignore;


  int emptySlots = connections.size();
  
  cout << "SIZZZE: " << emptySlots << endl;

  bool dataLoc[emptySlots];
  for (int i = 0; i < emptySlots; ++i)
    dataLoc[i] = false;

  for (int i = 0; i < size; ++i) {
    ModuleConnection mc = edges.at(i);

#ifdef D_MATT
    cout << "Got edge " << i << ": " << mc.getWeight() << endl;
#endif

    const int v1 = mc.getVertexOne();
    const int v2 = mc.getVertexTwo();
    int weight = mc.getWeight();

    if (emptySlots == connections.size()) {
      //add the two right away
      result.push_back(v1);
      result.push_back(v2);

      dataLoc[v1] = dataLoc[v2] = true;
      emptySlots -= 2;

#ifdef D_MATT
      cout << "Adding: " << v1 << " - " << v2 << endl;
#endif

    } else if (dataLoc[v1] == false && dataLoc[v2] == true) {
      //v1 not in result yet, v2 does exist, add v1
      //find the index of v2
      addToResult(result, v1, v2, weight);
      dataLoc[v1] = true;
      emptySlots--;
#ifdef D_MATT
      cout << "ADding " << v1 << endl;
#endif

    } else if (dataLoc[v1] == true && dataLoc[v2] == false) {
      //v2 not in result yet, v1 does, add v2
      addToResult(result, v2, v1, weight);
      dataLoc[v2] = true;
      emptySlots--;
#ifdef D_MATT
      cout << "Adding " << v2 << endl;
#endif

    } else {
      ignore.push(mc);
#ifdef D_MATT
      cout << "Adding to ignore list\n";
#endif

    }
  }
  while (!ignore.empty() && emptySlots > 0) {
    ModuleConnection mc = ignore.front();
    const int v1 = mc.getVertexOne();
    const int v2 = mc.getVertexTwo();
    const int weight = mc.getWeight();

    if (dataLoc[v1] == false && dataLoc[v2] == true) {
      addToResult(result, v1, v2, weight);
      dataLoc[v1] = true;
      emptySlots--;
#ifdef D_MATT
      cout << "ADding from ignore list: " << v1 << endl;
#endif

    } else if (dataLoc[v1] == true && dataLoc[v2] == false) {
      addToResult(result, v2, v1, weight);
      dataLoc[v2] = true;
      emptySlots--;
#ifdef D_MATT
      cout << "Adding from ignore list: " << v2 << endl;
#endif

    } else if (dataLoc[v1] == false && dataLoc[v2] == false) {
#ifdef D_MATT
      cout << "Putting (v1, v2) (" << v1 << ", " << v2 << ") back at the end!\n";
#endif
      ignore.push(mc);
    }
    ignore.pop();

  }
  
  return result;

}


bool shouldAddToStart(int listSize, int index, int weight) {
  return (index * weight) < ((listSize - index) * weight);
}
void addToResult(vector<int>& list, int moduleToAdd, int moduleAlreadyInThere, int weight) {
  int index = -1;
  for (unsigned int i = 0; i < list.size(); i++)
    if (list.at(i) == moduleAlreadyInThere)
      index = i;
  if (index == -1) {
    cout << "ERRORRRRR\n";
    return;
  }

  if (shouldAddToStart(list.size(), index, weight)) {
    list.insert(list.begin(), moduleToAdd);
  } else {
    list.insert(list.end(), moduleToAdd);
  }
}
