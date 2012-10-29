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
#include "BuildUp.h"

using namespace std;

int main () {

    string test = "HELLOWORLD";
    cout << "Dynamic programming algorithm to find the maximum palindromic"\
        " subsequence of: " << test << endl;

    BuildUp mananger( test );

    mananger.initArray();
    mananger.populateDiagonal();
    while ( mananger.hasNextDiagonal() ) {
        while ( mananger.hasNextCell() ) {
            mananger.calcCell();
            mananger.incrementCell();
        } 
        mananger.incrementDiagonal();
    }

    cout << mananger.getPalindromeSubsequence() << endl;

}
