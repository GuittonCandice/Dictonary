//
//  LinkedListFileHandler.h
//  Dictionary
//
//  Created by Candice on 19/11/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#ifndef LinkedListFileHandler_h
#define LinkedListFileHandler_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"

/** function to write words in file
 * @param ll Dictionary
 * @param path path of the file
 * @return int 1 if ok 0 if not
 **/

int LinkedListWriteToFile(LinkedList* ll, char* path);

/** function to read from file
 * @param path Dictionary
 * @return LinkedList of words
 **/
LinkedList* LinkedListReadFromFile(char* path);


#endif /* LinkedListFileHandler_h */
