//
//  LinkedList.c
//  LinkedList_h
//
//  Created by Candice on 13/11/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>


LinkedList* LinkedListNewElement(char* word){
    LinkedList* ll = malloc(sizeof(LinkedList));
    char* value = malloc(sizeof(char)*strlen(word));
    strcpy(value, word);
    ll->val = value;
    ll->next = NULL;
    
    return ll;
}

LinkedList* LinkedListAppend(LinkedList** head, char* word){
    
    LinkedList* previous = NULL;
    LinkedList* ll;
    LinkedList* current = *head;
    while(1) {
        int nb = current != NULL ? strcasecmp(current->val, word) : 1 ;
        if(nb == 0) {
            return NULL;
        }
        if(nb > 0){
            ll = LinkedListNewElement(word);
            if(previous == NULL) {
                *head = ll;
            }else {
                previous->next = ll;
            }
            ll->next = current;
            return ll;
        }
        previous = current;
        current = current->next;
    }
    return NULL;
}

void LinkedListPrint(LinkedList* head){
    while(head != NULL) {
        printf("%s ", head->val);
        head = head->next;
    }
    
}

int LinkedListSize(LinkedList* head){
    int size = 0;
    while(head != NULL) {
        size++;
        head = head->next;
    }
    
    return size;
}

int LinkedListContains(LinkedList* head, char* word){
    while(head != NULL) {
        int nb = strcasecmp(word, head->val);
        if(nb == 0){
            return 1;
        } else if (nb < 0) {
            return 0;
        }
        head = head->next;
        
    }
    return 0;
}




