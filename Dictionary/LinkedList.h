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

/** function to create LinkedList
 * @param word word to add
 * @return head of LinkedList
 **/
LinkedList* LinkedListNewElement(char* word);

/** function to add a word in LinkedList
 * @param head dictionary
 * @param word new word
 * @return LinkedList with the added word
 **/
LinkedList* LinkedListAppend(LinkedList** head, char* word);

/** function to display the entire dictionary
 * @param head Dictionary
 **/
void LinkedListPrint(LinkedList* head);

/** function to count the size of the linkedlist
 * @param head Dictionary
 * @return number of link
 **/
int LinkedListSize(LinkedList* head);

/** function to verify if a word exists in dictionary
 * @param head Dictionary
 * @param word word to find
 * @return int 1 if yes 0 if no
 **/
int LinkedListContains(LinkedList* head, char* word);



#endif /* LinkedList_h */
