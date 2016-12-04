//
//  menu_gestrech.c
//  Dictionary
//
//  Created by Candice on 04/12/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#include "menu_gestrech.h"

void displayHomeMenuGestRech(){

        printf("Projet C : Dictionnaire Partie 2\nPour faire une recherche à l'aide d'un seuil : \n\n");
        
        LinkedList* ll = chooseDictionaryMenu();
        searchWithThresholdMenu(ll);
    
}


void searchWithThresholdMenu(LinkedList* dictionary) {
    int threshold = 0;
    char word[255];
    printf("Veuillez saisir un seuil pour effectuer votre recherche \n" );
    scanf("%d", &threshold);
    printf("Veuillez saisir un mot \n");
    scanf("%s", word);
    LinkedListPrint(seekSimilarWord(dictionary, word, threshold));
    
}



