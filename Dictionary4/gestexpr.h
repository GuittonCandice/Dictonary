//
//  gestexpr.h
//  Dictionary
//
//  Created by Candice on 11/12/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#ifndef gestexpr_h
#define gestexpr_h

#include <stdio.h>
#include "menu_gestexpr.h"

/** function to analize the regex
 * @param regex the regex entered by the user
 * @param ll Dictionnay
 * @return error code
 **/
int analizeRegex (char regex[], LinkedList* ll);

/** function find the good regex when starting by a letter
 * @param regex the regex entered by the user
 * @param ll Dictionnary
 * @return error code
 **/
int startingByLetterTest (char regex[], LinkedList* ll);

/** function to get the index of a char
 * @param regex the regex entered by the user
 * @param searched the char searched
 * @param regexSize the size of the regex
 * @return index
 **/
int indexOf (char regex[], char searched, int regexSize);

/** function to get the second part of the regex
 * @param regex the regex entered by the user
 * @param start the start of the second part
 * @param regexSize the size of the regex
 * @return x
 **/
char* getX (char regex[], int start, int regexSize);

/** function to get the first part of the regex
 * @param regex the regex entered by the user
 * @param end the end of the first part of the regex
 * @return a
 **/
char* getA (char regex[], int end);

/** function search word with a*x
 * @param a first part of the regex
 * @param b second part of the regex
 * @param ll Dictionary
 **/
void regexRepeat0ToN(char* a, char* b, LinkedList* ll);

/** function search word with a?x
 * @param a first part of the regex
 * @param b second part of the regex
 * @param ll Dictionary
 **/
void regexRepeat0To1(char* a, char* b, LinkedList* ll);

/** function search word with a+x
 * @param a first part of the regex
 * @param b second part of the regex
 * @param ll Dictionary
 **/
void regexRepeat1ToN (char* a, char* b, LinkedList* ll);

#endif /* gestexpr_h */
