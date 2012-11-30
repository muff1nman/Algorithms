/*
 * =====================================================================================
 *
 *       Filename:  Helper.h
 *
 *    Description:  Just some helper functions
 *
 *        Version:  1.0
 *        Created:  11/30/2012 11:29:25 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew DeMaria (muff1nman), ademaria@mines.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#pragma once

void printVector( std::vector<int> toPrint ) {
    for ( int i = 0 ; i < toPrint.size(); ++i ) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
