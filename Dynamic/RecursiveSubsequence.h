#include <string>
#include <iostream>
#include <vector>

/*
 * This calculates the largest subsequence that is a palindrome... Tri's alg.
 */
static std::string LongestPalindromeSubsequence(std::string str)
{
    // Base case: string is one character.
    if (str.length() == 1)
        return str;

    // Base case:: string is only 2 the same character.
    if (str[0] == str[1] && str.length() == 2)
        return str;

    // Both ends of the string is the same.
    if (str[0] == str[str.length()-1]) {
        return str[0] + LongestPalindromeSubsequence(str.substr(1, str.length()-2)) + str [0];
    }

    // Neither ends of of the string is the same.
    std::string left = LongestPalindromeSubsequence(str.substr(0, str.length()-1));
    std::string right = LongestPalindromeSubsequence(str.substr(1));
    return (left.length() <= right.length()) ? right : left;
}

/*
 * This calculates the largest subsequence that is a palindrome... Tri's alg.
 */
static std::string LongestPalindromeSubsequenceDynamic(std::string str)
{
    std::vector<std::vector<std::string> > palindromeTable;

    // Fill the array with blanks spaces.
    for(unsigned int i = 0; i < str.length(); i++) {
        std::vector<std::string> temp;
        for (unsigned int j = 0; j < str.length(); j++) {
            temp.push_back(" ");
        }
        palindromeTable.push_back(temp);
    }

    // Fill the array's diagonal with character of the strings.
    for (unsigned int i = 0; i < str.length(); i++) {
       palindromeTable[i][i] = str[i];
    }


    for (unsigned int substringLength = 2; substringLength <= str.length(); substringLength++)
    {
        for (unsigned int i = 0; i < str.length() - substringLength + 1; i++)
        {
            int j = i + substringLength - 1;
            if (str[i] == str[j] && substringLength == 2) {
                palindromeTable[i][j] = str.substr(i, 2);
            }
            else if (str[i] == str[j]) {
                palindromeTable[i][j] = str[i] + palindromeTable[i+1][j-1] + str[j];
            }
            else {
                std::string left = palindromeTable[i][j-1];
                std::string right = palindromeTable[i+1][j];
                palindromeTable[i][j] =  (left.length() <= right.length()) ?  right : left;
            }
        }
    }
    return palindromeTable[0][str.length()-1];
}

/*
 * This calculates the largest subsequence that is a palindrome... Andrew's alg.
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
