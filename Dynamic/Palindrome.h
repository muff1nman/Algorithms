/*
 * =====================================================================================
 *
 *       Filename:  Palindrome.h
 *
 *    Description:  Our palindrome library
 *
 *        Version:  1.0
 *        Created:  10/20/2012 10:58:56 AM
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

#include <cstdlib>
#include <string>
#include <stack>
#include <queue>

#pragma once


/* 
 * isPalindrome returns true if the given string with the given length is a
 * palindrome. The algorithm utilizes a stack and a queue to compare the inorder
 * characters with the reverse order characters
 */
static bool isPalindrome( const char* string, int length ){
    std::stack<char> theStack;
    std::queue<char> theQueue;

    // fill up the stack and the queue
    for( int i = 0; i< length; ++i ) {
        theStack.push( string[i] );
        theQueue.push( string[i] );
    }

    // empty both stack and queue
    while( ! theStack.empty() && ! theQueue.empty() ) {

        // compare the characters
        if ( theStack.top() != theQueue.front() ) {
            return false;
        }

        // and remove the character at the top, moving to the next character
        theStack.pop();
        theQueue.pop();
    }

    return true;

}

/*
 * This calculates the largest palindrome in O(2^n) time using a recursive
 * element.  The idea is that if the string is a palindrome, return the length
 * of the string, otherwise return the larger length of either the string with
 * the first character removed or the last character removed. 
 */
static size_t maxPalindrome( const std::string& someString ) {
    // check for a palindrome of the given string
    if ( isPalindrome( someString.c_str(), someString.length() ) ) {
        return someString.length();
    } else {
        // get the left and right substrings
        std::string left = someString.substr( 0, someString.length() - 1 );
        std::string right = someString.substr( 1, someString.length() - 1 );

        // calculate the maximum palindrome length in those substrings
        size_t maxFromLeft = maxPalindrome( left );
        size_t maxFromRight = maxPalindrome( right );

        // return the larger length
        if ( maxFromLeft < maxFromRight ) {
            return maxFromRight;
        } else {
            return maxFromLeft;
        }
    }
}
