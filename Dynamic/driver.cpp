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
    cout << someString2 << " has palindrome subsequence: " <<  tablematchManager.findMax() << endl;

    string another1 = "catc";
    tablematchManager = TableMatch( another1 );
    cout << another1 << " has palindrome subsequence: " <<  tablematchManager.findMax() << endl;


    string smaller = "catc";
    cout << "String: " << smaller << endl;
    cout << "Longest subsequence: " << maxSequencePalindrome( smaller) << endl;

}
