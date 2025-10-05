#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int SET[MAX];

// Populate set with 0/1 array
void populateSet(SET S) {
    // Initialize all elements to 0
    for (int i = 0; i < MAX; i++)
        S[i] = 0;

    for (int i = 0; i < MAX; i++) {
        int data;
        printf("Element %d (0-%d): ", i, MAX-1);
        scanf("%d", &data);

        if(data >= 0 && data < MAX) {
            S[data] = 1;
        }
    }
    printf("\n");
}

// Print the set
void printSet(SET S) {
    printf("{ ");
    for (int i = 0; i < MAX; i++) {
        if(S[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

// Union of two sets
SET *UNION(SET A, SET B){
    SET *C = malloc(sizeof(SET));
    for(int i = 0 ; i < MAX ; i++){
        if(A[i] == 1 || B[i] == 1){
            (*C)[i] = 1;  // Use =, not ==
        }
        else{
            (*C)[i] = 0;
        }
    }
    return C;
}

// Intersection of two sets
SET *INTERSECT(SET A, SET B){
    SET *C = malloc(sizeof(SET));
    for(int i = 0 ; i < MAX ; i++){
        if(A[i] == 1 && B[i] == 1){
            (*C)[i] = 1;
        }
        else{
            (*C)[i] = 0;
        }
    }
    return C;
}

// Difference of two sets (A - B)
SET *DIFFERENCE(SET A, SET B){
    SET *C = malloc(sizeof(SET));
    for(int i = 0 ; i < MAX ; i++){
        if(A[i] != B[i] && A[i] != 0){
            (*C)[i] = 1;
        }
        else{
            (*C)[i] = 0;
        }
    }
    return C;
}

int main(){
    // Clear screen
    printf("\033[H\033[J");

    SET A, B;
    populateSet(A);
    populateSet(B);

    printf("Set A: ");
    printSet(A);

    printf("Set B: ");
    printSet(B);

    SET *U = UNION(A, B);
    printf("\nUnion: ");
    printSet(*U);

    SET *I = INTERSECT(A, B);
    printf("Intersection: ");
    printSet(*I);

    SET *D1 = DIFFERENCE(A, B);
    printf("A - B: ");
    printSet(*D1);

    SET *D2 = DIFFERENCE(B, A);
    printf("B - A: ");
    printSet(*D2);

    // Free allocated memory
    free(U);
    free(I);
    free(D1);
    free(D2);

    return 0;
}

