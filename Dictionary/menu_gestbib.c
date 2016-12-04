//
//  menu_gestbib.h
//  Dictionary
//
//  Created by Candice on 27/11/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#include "menu_gestbib.h"


void displayHomeMenuGestBib(){
    int choice = 0;

    do {
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
    } while (choice != 0);
}

void createDictionaryMenu() {
    char word[255];
    printf("Pour créer un dictionnaire, saisissez un mot et faites entrée autant de fois que nécessaire, faites 0 pour arrêter\n");
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

LinkedList* chooseDictionaryMenu(){
    char path[255];
    int choice;
    printf("Saisissez le chemin du dictionnaire que vous voulez utiliser\n");
    scanf("%s", path);
    LinkedList* ll = LinkedListReadFromFile(path);
    printf("Voulez vous afficher ce dictionnaire ? 1 pour oui, 0 pour non \n");
    scanf("%d", &choice);
    if(choice == 1) {
        LinkedListPrint(ll);
        printf("\n");
    } else {
        return ll;
    }
    return ll;
}

void buildDictionaryMenu(){
    char path[255];
    char path2[255];
    printf("Saisissez le chemin du fichier texte que vous voulez utiliser\n");
    scanf("%s", path);
    LinkedList* ll = NULL;
    ll = LinkedListReadFromFile(path);
    printf("Saisissez l'endroit ou vous voulez placer le dictionnaire créé\n");
    scanf("%s", path2);
    LinkedListWriteToFile(ll, path2);
}

void insertInDictionaryMenu(){
    char path[255];
    char word [255];
    printf("Saisissez le chemin du dictionnaire dans lequel vous voulez insérer un mot\n");
    scanf("%s", path);
    printf("Saisissez le mot\n");
    scanf("%s", word);
    LinkedList* ll = LinkedListReadFromFile(path);
    if(LinkedListAppend(&ll, word) == NULL) {
        printf("Echec de l'insertion\n\n");
    }else {
        printf("Votre mot a bien été inséré\n\n");
        LinkedListWriteToFile(ll, path);
        LinkedListPrint(ll);

    };
    
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
        printf("Le dictionnaire contient le mot \"%s\" \n\n", word);
    } else {
        printf("Le dictionnaire ne contient pas le mot \"%s\" \n\n", word);

    }
}

void deleteDictionaryMenu(){
    char path[255];
    printf("Saisissez le chemin du dictionnaire que vous voulez effacer\n");
    scanf("%s", path);
    if(remove(path) == 0) {
        printf("Le dictionnaire a bien été effacé\n\n");
    } else {
        printf("La suppression du dictionnaire a échoué\n\n");
    }
    
}
