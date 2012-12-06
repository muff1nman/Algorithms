/*
 * =====================================================================================
 *
 *       Filename:  ModuleConnection.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/05/2012 06:09:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew DeMaria (muff1nman), ademaria@mines.edu
 *   Organization:  Colorado School of Mines
 *
 * =====================================================================================
 */

#pragma once


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
