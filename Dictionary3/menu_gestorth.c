//
//  menu_gestorth.c
//  Dictionary
//
//  Created by Candice on 04/12/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#include "menu_gestorth.h"


void displayHomeMenuGestOrth() {
    int choice = 0;
    
    do {
        printf("Projet C : Dictionnaire Partie 3\n1/ Liste des mots n'existant pas dans le dictionnaire choisi + ligne \n2/Liste des mots n'existant pas dans le dictionnaire choisi + liste mots proches (seuil 2) \n3/ Construction d'un fichier corrigé (seuil 1)\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                verifyDictionaryMenu(choice);
                break;
            case 2:
                verifyDictionaryMenu(choice);
                break;
            case 3:
                buildCorrectedFile();
                break;
            default:
                break;
        }
    } while (choice != 0);
}

void verifyDictionaryMenu(choice) {
    if(choice == 1) {
        //liste mots + ligne
    } else {
        //liste mots + mots proche (seuil 2)
    }
}

FILE* buildCorrectedFile() {
    FILE* f;
    return f;
}

