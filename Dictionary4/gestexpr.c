//
//  gestexpr.c
//  Dictionary
//
//  Created by Dylan & Candice on 11/12/2016.
//  Copyright © 2016 Dylan & Candice. All rights reserved.
//

#include "gestexpr.h"

void regexRepeat1ToN (char* a, char* b, LinkedList* ll) {
    int i;
    int j = 0;
    int k = 0;
    int testPartOne = 0;
    int found = 0;
    
    while(ll != NULL) {
        j = 0;
        k = 0;
        testPartOne = 0;
        
        for (i = 0; i < strlen(ll->val); i++) {
            
            if(testPartOne == 0) {
                if (ll->val[i] == a[j]) {
                    j++;
                } else {
                    if (j != 0) {
                        break;
                    }
                }
                if (j == strlen(a)){
                    testPartOne++;
                }
                
            } else {
                if (ll->val[i] == b[k]) {
                    k++;
                }
                if (k == strlen(b)){
                    printf("%s ", ll->val);
                    found++;
                }
            }
        }
        ll = ll->next;
    }
    
    if (found == 0) {
        printf("Aucun resultat");
    }
    printf("\n\n");
    
}

void regexRepeat0To1(char* a, char* b, LinkedList* ll) {
    int i;
    int j = 0;
    int found = 0;
    
    while(ll != NULL) {
        j = 0;
        
        for (i = 0; i < strlen(ll->val); i++) {
            
            if (ll->val[i] == b[j]) {
                j++;
            }
            if (j == strlen(b)){
                printf("%s ", ll->val);
                found++;
                break;
            }
        }
        ll = ll->next;
    }
    
    if (found == 0) {
        printf("Aucun resultat");
    }
    printf("\n\n");
    
}

void regexRepeat0ToN(char* a, char* b, LinkedList* ll) {
    int i;
    int j = 0;
    int found = 0;
    
    while(ll != NULL) {
        j = 0;
        
        for (i = 0; i < strlen(ll->val); i++) {
            
            if (ll->val[i] == b[j]) {
                j++;
            }
            if (j == strlen(b)){
                printf("%s ", ll->val);
                found++;
                break;
            }
        }
        ll = ll->next;
    }
    
    if (found == 0) {
        printf("Aucun resultat");
    }
    printf("\n\n");
    
}

char* getA (char regex[], int end) {
    char* a = malloc(sizeof(char)*50);
    int i;
    
    for (i = 0; i < end; i++) {
        a[i] = regex[i];
    }
    
    return a;
}

char* getX (char regex[], int start, int regexSize) {
    char* x = malloc(sizeof(char)*50);
    int i;
    int j = 0;
    
    for (i = start+1; i < regexSize; i++) {
        x[j] = regex[i];
        j++;
    }
    
    return x;
}

int indexOf (char regex[], char searched, int regexSize) {
    int i;
    
    for (i = 0; i < regexSize; i++) {
        if (regex[i] == searched) {
            return i;
        }
    }
    return -1;
}

int startingByLetterTest (char regex[], LinkedList* ll) {
    int regexSize = (int) strlen(regex);
    int id = 0;
    
    id = indexOf(regex, '*', regexSize);
    if (id >= 0) {
        regexRepeat0ToN(getA(regex, id), getX(regex, id, regexSize), ll);
    } else {
        id = indexOf(regex, '?', regexSize);
        if (id >= 0) {
            regexRepeat0To1(getA(regex, id), getX(regex, id, regexSize), ll);
        } else {
            id = indexOf(regex, '+', regexSize);
            if (id >= 0) {
                regexRepeat1ToN(getA(regex, id), getX(regex, id, regexSize), ll);
            } else {
                return 0;
            }
        }
        
    }
    
    return 1;
}

int analizeRegex (char regex[], LinkedList* ll) {
    int verified = 0;
    
    if (regex[0] <= 'z' && regex[0] >= 'a') {
        verified = startingByLetterTest(regex, ll);
    }
    
    return verified;
}
