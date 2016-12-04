//
//  gestrech.c
//  Dictionary
//
//  Created by Candice on 04/12/2016.
//  Copyright © 2016 Candice. All rights reserved.
//

#include "gestrech.h"

/**
 * Fonction de Levenshtein qui calcul le seuil entre deux mots
 * @param word mot cherché par l'utilisateur
 * @param wordLength taille du mot cherché
 * @param wordCompared mot comparé
 * @param wordComparedLength taille du mot comparé
 * @return matrix[wordLength][wordComparedLength] le seuil de difference le plus petit entre les deux chaînes
 */

int levenshtein(char* word, int wordLength, char* wordCompared, int wordComparedLength) {
    
    int matrix[wordLength + 1][wordComparedLength + 1]; // Creation et initialisation de la matrice de comparaison
    int i;
    for (i = 0; i <= wordLength; i++) {
        matrix[i][0] = i;
    }
    for (i = 0; i <= wordComparedLength; i++) {
        matrix[0][i] = i;
    }
    for (i = 1; i <= wordLength; i++) { // Parcours de word
        int j;
        char c1;
        
        c1 = word[i-1];
        for (j = 1; j <= wordComparedLength; j++) { // Parcours de wordCompared
            char c2;
            
            c2 = wordCompared[j-1];
            if (c1 == c2) { // Si les caracteres sont les memes pas d'incrementation du compteur
                matrix[i][j] = matrix[i-1][j-1];
            }
            else {
                int delete;
                int insert;
                int substitute;
                int minimum;
                
                delete = matrix[i-1][j] + 1; // Test de l'effacement du caractere dans word
                insert = matrix[i][j-1] + 1; // Test de l'insertion du caractere de word dans wordCompared
                substitute = matrix[i-1][j-1] + 1; // Test de substitution du caratere
                
                minimum = delete; // Test pour determiner lequel des derniers test coûte le moins soit le plus petit seuil
                if (insert < minimum) {
                    minimum = insert;
                }
                if (substitute < minimum) {
                    minimum = substitute;
                }
                matrix[i][j] = minimum;
            }
        }
    }
    return matrix[wordLength][wordComparedLength]; // Retourne le dernier seuil trouver lors de la recherche
    
}


LinkedList* seekSimilarWord(LinkedList* dictionary, char* word, int threshold) {
    int wordlength = (int)strlen(word);
    LinkedList* output = NULL;
    while(dictionary != NULL) {
        if(levenshtein(word, wordlength, dictionary->val, (int)strlen(dictionary->val)) <= threshold){
            LinkedListAppend(&output, dictionary->val);
        }
        dictionary = dictionary->next;
    }
    return output;
}


