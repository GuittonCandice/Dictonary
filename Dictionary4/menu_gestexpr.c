//
//  menu_gestexpr.c
//  Dictionary
//
//  Created by Candice on 11/12/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#include "menu_gestexpr.h"


void displayHomeMenuGestExpr() {
    int choice = 0;
    
    do {
        printf("Projet C : Dictionnaire Partie 4\n1/ Liste des mots résultant de l'expression régulière saisie par l'utilisateur \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:{
                LinkedList* ll = chooseDictionaryMenu();
                
            }
                break;
            default:
                break;
        }
    } while (choice != 0);
}

void chooseRegex() {
    
}
