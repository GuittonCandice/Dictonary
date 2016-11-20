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
#include "LinkedList.h"

int LinkedListWriteToFile(LinkedList*, char*);

LinkedList* LinkedListReadFromFile(char*);


#endif /* LinkedListFileHandler_h */
