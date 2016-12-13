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
            case 1:{
                char path[255];
                printf("Saisissez le chemin du fichier texte que vous voulez utiliser\n");
                scanf("%s", path);
                LinkedList* ll = chooseDictionaryMenu();
                verifyFile(ll, path);
            }
                break;
            case 2:
                break;
            case 3:
                buildCorrectedFile();
                break;
            default:
                break;
        }
    } while (choice != 0);
}

void verifyFile(LinkedList* ll, char* path) {
    FILE* file = fopen(path, "r");
    int line = 1;
    char word[255];
    char c;
    int index = 0;
    
    while((c = fgetc(file)) != EOF){
        if(c == '\n'){
            line++;
        }else if(c == ' '){
            word[index] = '\0';
            index = 0;
            if((LinkedListContains(ll, word)) == 0){
                printf("%d %s", line, word);
            }
        }else {
            word[index] = c;
            index++;
        }
    }
    
    
}

FILE* buildCorrectedFile() {
    FILE* f;
    return f;
}

