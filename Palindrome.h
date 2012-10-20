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
 *         Author:  Andrew DeMaria (), ademaria@mines.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <string>
#include <stack>
#include <queue>

#pragma once

static bool isPalindrome( const char* string, int length ){
    std::stack<char> theStack;
    std::queue<char> theQueue;

    for( int i = 0; i< length; ++i ) {
        theStack.push( string[i] );
        theQueue.push( string[i] );
    }

    while( ! theStack.empty() && ! theQueue.empty() ) {
        if ( theStack.top() != theQueue.front() ) {
            return false;
        }

        theStack.pop();
        theQueue.pop();
    }

    return true;

}

static size_t maxPalindrome( const std::string& someString ) {
    if ( isPalindrome( someString.c_str(), someString.length() ) ) {
        return someString.length();
    } else {
        std::string left = someString.substr( 0, someString.length() - 1 );

        std::string right = someString.substr( 1, someString.length() - 1 );

        size_t maxFromLeft = maxPalindrome( left );
        size_t maxFromRight = maxPalindrome( right );
        if ( maxFromLeft < maxFromRight ) {
            return maxFromRight;
        } else {
            return maxFromLeft;
        }
    }
}
