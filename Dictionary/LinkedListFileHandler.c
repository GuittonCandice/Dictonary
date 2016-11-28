//
//  LinkedListFileHandler.c
//  Dictionary
//
//  Created by Candice on 19/11/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#include "LinkedListFileHandler.h"

static char notChar[27] =  {'\n', ',', ' ', '.', ';', ':', '/', '?', '\t', '!', '&', '|', '*', '+', '-', '_', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '$' };

int LinkedListWriteToFile(LinkedList* ll, char* path) {
    FILE* file = fopen(path, "w");
    
    if(file == NULL) {
        return 0;
    }
    
    while(ll != NULL) {
        fprintf(file, "%s\n", ll->val);
        ll = ll->next;
    }
    fclose(file);
    
    return 1;
}

int isChar(char c) {
    for (int i = 0 ; i<27; i++) {
        if(c == notChar[i]) {
            return 0;
        }
    }
    return 1;
}

LinkedList* LinkedListReadFromFile(char* path) {
    FILE* file = fopen(path, "r");
    
    if(file == NULL) {
        return 0;
    }
    
    LinkedList* ll = NULL;
    char buffer[255];
    char c;
    int i = 0;
    while((c = fgetc(file)) != EOF) {
        if(isChar(c)) {
            buffer[i] = c;
            i++;
        } else if(i > 0){
            buffer[i] = '\0';
            LinkedListAppend(&ll, buffer);
            i = 0;
        }
        
    }
    
    return ll;
}
