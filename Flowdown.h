/*
 * =====================================================================================
 *
 *       Filename:  Flowdown.h
 *
 *    Description:  A dynamic programming attempt using a flow down approach to
 *                  calculate the maximum palindrome length.  
 *
 *        Version:  1.0
 *        Created:  10/20/2012 12:52:44 PM
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
#include <vector>
#include <iostream>
#include "Palindrome.h"

#pragma once

class Flowdown {

    public:
        Flowdown(std::string palindrome);
        std::string  getMaximum();
        void calcMaximum();
        void reserveTable();
        void printTable();

    private:
        std::string initdrome;
        std::vector<std::vector<int> > table;

        void populateTable();
        std::string actPalindrome;
};

