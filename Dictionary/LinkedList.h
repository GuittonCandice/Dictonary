//
//  LinkedList.h
//  LinkedList
//
//  Created by Candice on 13/11/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>


struct LinkedList {
    char* val;
    struct LinkedList *next;
    
};
typedef struct LinkedList LinkedList;

LinkedList* LinkedListNewElement(char* word);

LinkedList* LinkedListAppend(LinkedList** head, char* word);

void LinkedListPrint(LinkedList* head);

int LinkedListSize(LinkedList* head);

int LinkedListContains(LinkedList* head, char* word);



#endif /* LinkedList_h */
