//
//  main.c
//  Dictionary
//
//  Created by Candice on 13/11/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"
#include "LinkedListFileHandler.h"

int main(int argc, const char * argv[]) {

    
    LinkedList* ll = LinkedListNewElement("Bonjour");
    
    LinkedListAppend(&ll, "Abou");
    LinkedListAppend(&ll, "Candice");
    LinkedListAppend(&ll, "Zebre");
    LinkedListAppend(&ll, "Hippopotame");
    LinkedListAppend(&ll, "Benoit");
    
   // LinkedListPrint(ll);
  //  printf("%d", LinkedListSize(ll));
   // printf("\n%d ",LinkedListContains(ll, "Bruno"));
    
    
    LinkedListWriteToFile(ll, "/Users/candice/Desktop/dic1.txt");

    LinkedList* ll2 = LinkedListReadFromFile("/Users/candice/Desktop/lorem.txt");
    LinkedListWriteToFile(ll2, "/Users/candice/Desktop/dic2.txt");
    
    
    char* string = "bonjour les petits chats";
    int i=0, cpt = 0;

    while(string[i] != '\0') {
        if(string[i] == ' '){
            cpt++;
        }
        i++;
    }
   // printf("%d", cpt);
    
    
    return 0;
}
