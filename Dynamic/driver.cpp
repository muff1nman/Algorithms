/*
 * =====================================================================================
 *
 *       Filename:  driver.cpp
 *
 *    Description:  Dynamic programming algorithm for finding the maximum
 *                  palindrome.
 *
 *        Version:  1.0
 *        Created:  10/20/2012 10:51:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew DeMaria, ademaria@mines.edu
 *                  Tri Nguyen, tringuye@mines.edu
 *                  Maria Deslis, mdeslis@mines.edu
 *   Organization:  Colorado School of Mines
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Palindrome.h"
#include "Flowdown.h"
#include "RecursiveSubsequence.h"
#include "TableMatch.h"

using namespace std;

int main () {
    cout << "Dynamic programming algorithm to find the maximum palindrome" <<
        endl;

    string someString2 = "ACGTGTCAAAATCG";

    TableMatch tablematchManager( someString2 );
//    tablematchManager.generateEmptyTable();
//    tablematchManager.findMatches();
//    tablematchManager.printTable();
//    for ( unsigned int i = someString2.size() ; i != 0; --i ) {
//        tablematchManager.processRow(i - 1);
//        tablematchManager.printSequences();
//    }
//
//    tablematchManager.generateString();

    cout << tablematchManager.findMax() << endl;

//    string smaller = "tq";
//
//    cout << "String: " << smaller << endl;
//    cout << "Longest subsequence: " << maxSequencePalindrome( smaller) << endl;
//
//    cout << "String: " << someString2 << endl;
//    Flowdown flowmanager1(someString2);
//    flowmanager1.printTable();
//    flowmanager1.calcMaximum();
//    cout << "Longest: " << flowmanager1.getMaximum() << " size: " << flowmanager1.getMaximum().size()<< endl << endl;
//
//    string someString1 = "racecar";
//    cout << "String: " << someString1 << endl;
//    Flowdown flowmanager2(someString1);
//    flowmanager2.calcMaximum();
//    cout << "Longest: " << flowmanager2.getMaximum() << " size: " << flowmanager2.getMaximum().size() << endl << endl;
//
//    string someString = "gama";
//    cout << "String: " << someString << endl;
//    Flowdown flowmanager3(someString);
//    flowmanager3.printTable();
//    flowmanager3.calcMaximum();
//    cout << "Longest: " << flowmanager3.getMaximum() << " size: " << flowmanager3.getMaximum().size() << endl << endl;
}
