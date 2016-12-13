//
//  menu_gestorth.h
//  Dictionary
//
//  Created by Candice on 04/12/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#ifndef menu_gestorth_h
#define menu_gestorth_h

#include <stdio.h>
#include "gestbib.h"
#include "gestrech.h"
void displayHomeMenuGestOrth();


void verifyFile(LinkedList* ll, char* path);

void verifyDictionaryWordsMenu();

void closeWord(LinkedList* ll, char* path);

FILE* buildCorrectedFile();
#endif /* menu_gestorth_h */
