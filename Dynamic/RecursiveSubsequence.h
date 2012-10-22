#include <stdio.h>
#include <string>
#include <iostream>

static std::string max (std::string& x, std::string& y) {
    return ( x.size() >= y.size() ) ? x : y;
}

static std::string LongestPalindromeSubsequence(std::string str)
{
    // Base case: string is one character.
    if (str.size() == 1)
        return str;

    // Base case:: string is only 2 the same character.
    if (str[0] == str[1] && str.size() == 2)
        return str;

    // Both ends of the string is the same.
    if (str[0] == str[str.size()-1]) {
        return str[0] + LongestPalindromeSubsequence(str.substr(1, str.size()-2)) + str [0];
    }

    // Neither ends of of the string is the same.
    std::string left = LongestPalindromeSubsequence(str.substr(0, str.size()-1));
    std::string right = LongestPalindromeSubsequence(str.substr(1));
    return ::max(left, right);
}


/*
 * This calculates the largest subsequence that is a palindrome
 */
static std::string maxSequencePalindrome( const std::string& someString ) {
    if ( isPalindrome( someString.c_str(), someString.length() ) ) {
        return someString;
    } else {
        std::string rightHalf;
        std::string leftHalf;
        std::string combined;

        size_t max = 0;
        std::string toReturn = "";
        std::string temp;
        // get the largest value from the following
        for (unsigned int i = 0; i < someString.length(); ++i ) {
            leftHalf = someString.substr(0, i);
            rightHalf = someString.substr(i+1);
            combined = leftHalf + rightHalf;

            temp = maxSequencePalindrome( combined );
            if ( max < temp.length() ) {
                max = temp.length();
                toReturn = temp;
            }
        }

        return toReturn;
    }
}
