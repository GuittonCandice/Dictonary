//
//  Menu.c
//  Dictionary
//
//  Created by Candice on 27/11/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#include "Menu.h"


void displayHomeMenu(){
    int choice = 0;
    printf("Projet C : Dictionnaire Partie 1\n1/ Créer un dictionnaire \n2/ Utiliser un dictionnaire existant \n3/ Fabriquer un dictionnaire à partir d'un fichier existant \n4/ Inserer un mot dans le dictionnaire \n5/ Rechercher un mot dans un dictionnaire \n6/ Détruire un fichier dictionnaire\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            createDictionaryMenu();
            break;
        case 2:
            chooseDictionaryMenu();
            break;
        case 3:
            buildDictionaryMenu();
            break;
        case 4:
            insertInDictionaryMenu();
            break;
        case 5:
            searchInDictionaryMenu();
            break;
        case 6:
            deleteDictionaryMenu();
            break;
        default:
            break;
    }
    
}

void createDictionaryMenu() {
    char word[255];
    printf("Pour créer un dictionnaire, saisissez un mot et faites entrée autant de fois que nécessaire\n");
    LinkedList* ll = NULL;
    do {
        
        scanf("%s",word);
        if(strcmp(word, "0") != 0){
            LinkedListAppend(&ll, word);
        } else {
            break;
        }

    }while(strcmp(word,"0") != 0);
    LinkedListPrint(ll);
    LinkedListWriteToFile(ll, "/Users/candice/Desktop/chaton.txt");
    
}

void chooseDictionaryMenu(){
    char path[255];
    printf("Saisissez le chemin du dictionnaire que vous voulez utiliser\n");
    scanf("%s", path);
    LinkedListPrint(LinkedListReadFromFile(path));
    
}

void buildDictionaryMenu(){
    char path[255];
    printf("Saisissez le chemin du fichier texte que vous voulez utiliser\n");
    scanf("%s", path);
    LinkedListPrint(LinkedListReadFromFile(path));
}

void insertInDictionaryMenu(){
    char path[255];
    char word [255];
    printf("Saisissez le chemin du dictionnaire dans lequel vous voulez insérer un mot\n");
    scanf("%s", path);
    printf("Saisissez le mot\n");
    scanf("%s", word);
    LinkedList* ll = LinkedListReadFromFile(path);
    LinkedListAppend(&ll, word);
    LinkedListPrint(ll);
    
}

void searchInDictionaryMenu(){
    char path[255];
    char word [255];
    printf("Saisissez le chemin du dictionnaire dans lequel vous voulez rechercher un mot\n");
    scanf("%s", path);
    printf("Saisissez le mot\n");
    scanf("%s", word);
    LinkedList* ll = LinkedListReadFromFile(path);
    if(LinkedListContains(ll, word) == 1) {
        printf("Le dictionnaire contient le mot \"%s\"", word);
    } else {
        printf("Le dictionnaire ne contient pas le mot \"%s\"", word);

    }
}

void deleteDictionaryMenu(){
    char path[255];
    printf("Saisissez le chemin du dictionnaire que vous voulez effacer\n");
    scanf("%s", path);
    if(remove(path) == 0) {
        printf("Le dictionnaire a bien été effacé");
    } else {
        printf("La suppression du dictionnaire a échoué");
    }
    
}
