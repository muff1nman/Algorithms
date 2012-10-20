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
 *                  Tri Nguyen
 *                  Maria Deslis
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Palindrome.h"

using namespace std;

int main () {
    cout << "Dynamic programming algorithm to find the maximum palindrome" <<
        endl;

    string someString = "helgabcqrp";
    string someString1 = "racecar";
    string someString2 = "ACGTTCTAAAATCG";

    cout << "Is " << someString << " a palindrome? " << isPalindrome( someString.c_str(), someString.length() ) << endl;
    cout << "max palindrome length: " << maxPalindrome( someString ) << endl;
    cout << "Calls to maxPalindrome: " << count << endl;
    count = 0;

    cout << "Is " << someString1 << " a palindrome? " << isPalindrome( someString1.c_str(), someString1.length() ) << endl;
    cout << "max palindrome length: " << maxPalindrome( someString1 ) << endl;
    cout << "Calls to maxPalindrome: " << count << endl;
    count = 0;

    cout << "Is " << someString2 << " a palindrome? " << isPalindrome( someString2.c_str(), someString2.length() ) << endl;
    cout << "max palindrome length: " << maxPalindrome( someString2 ) << endl;
    cout << "Calls to maxPalindrome: " << count << endl;
}
