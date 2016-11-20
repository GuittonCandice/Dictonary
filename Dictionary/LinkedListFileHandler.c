//
//  LinkedListFileHandler.c
//  Dictionary
//
//  Created by Candice on 19/11/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#include "LinkedListFileHandler.h"

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

LinkedList* LinkedListReadFromFile(char* path) {
    FILE* file = fopen(path, "r");
    
    if(file == NULL) {
        return 0;
    }
    
    LinkedList* ll = NULL;
    char tab[255];
    while((fgets("%s\n, <#int#>, <#FILE *#>)(file, "%s\n", tab)) != 0) {
        LinkedListAppend(&ll, tab);
    }
    
    return ll;
}
