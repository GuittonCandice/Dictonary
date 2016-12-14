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
    char regex[50];
    int verified = 0;
    
    do {
        printf("Projet C : Dictionnaire Partie 4\n1/ Liste des mots résultant de l'expression régulière saisie par l'utilisateur \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:{
                LinkedList* ll = chooseDictionaryMenu();
                printf("Saisissez votre expression :\n");
                scanf("%s", regex);
                verified = analizeRegex(regex, ll);
                if (verified == 0) {
                    printf("Expression non reconnue\n");
                }
            }
                break;
                
            default:
                printf("Saisie incorrecte\n");
                break;
        }
    } while (choice != 0);
}
