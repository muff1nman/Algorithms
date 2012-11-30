/*
 * =====================================================================================
 *
 *       Filename:  driver.cpp
 *
 *    Description:  Driver file for the final project
 *
 *        Version:  1.0
 *        Created:  11/22/2012 01:58:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew DeMaria (muff1nman), ademaria@mines.edu
 *                  Matt Stech, mstech@mines.edu
 *                  Aakash Shah, ashah@mines.edu
 *   Organization:  Colorado School of Mines
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include "input.h"
#include <utility>
#include "ConnMatrix.h"
#include <vector>
#include "Helper.h"
#include "Exhastive.h"

using namespace std;

int main () {
    cout << "    ALGO WARS" << endl;
    cout << "=================" << endl;

    ConnMatrix connections = import( "example1.txt" );

    printArray( connections );

    std::vector<int> solution = exhastive( connections );

    printVector( solution );

}


