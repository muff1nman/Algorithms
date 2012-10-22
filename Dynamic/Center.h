/*
 * =====================================================================================
 *
 *       Filename:  Center.h
 *
 *    Description:  This contains an alorithm to find the largest subsequence of
 *                  a string that is also a palindrome. 
 *
 *                  The idea is that every possible palindrome subsequence has a
 *                  center.  The center is either a null character between two
 *                  characters or an actual character.  For each of these
 *                  centers find the maximum palindrome subsequence using that
 *                  character as the center.  Then the largest max is the
 *                  largest subsequence.  
 *
 *        Version:  1.0
 *        Created:  10/22/2012 10:55:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew DeMaria (), ademaria@mines.edu
 *   Organization:  
 *
 * =====================================================================================
 */

