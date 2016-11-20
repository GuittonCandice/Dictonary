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
    
    LinkedListAppend(&ll, "Monamour");
    LinkedListAppend(&ll, "Abou");
    LinkedListAppend(&ll, "Candice");
    LinkedListAppend(&ll, "Zebre");
    LinkedListAppend(&ll, "Hippopotame");
    LinkedListAppend(&ll, "Benoit");
    
    LinkedListPrint(ll);
    printf("%d", LinkedListSize(ll));
    printf("\n%d ",LinkedListContains(ll, "Bruno"));
    
    
    LinkedListWriteToFile(ll, "/Users/candice/Desktop/dic1.txt");

    LinkedList* ll2 = LinkedListReadFromFile("/Users/candice/Desktop/dic1.txt");
    LinkedListPrint(ll2);
    
    return 0;
}
