#include <stdio.h>
#include <stdbool.h>

typedef unsigned char SET;

// Initialize the set to be empty (all bits set to 0)
void initSet(SET *A) {
    *A = 0;  
}

// Insert an element into the set
void insert(SET *A, int element) {
    *A |= (1 << element);  
}

// Display the elements of the set
void displaySet(SET *A) {

    for (int i = 0; i < 8; i++) {
        if (*A & (1 << i)) {  
            printf("%d ", i);
        }
    }
    
    printf("\n");
}

// Check if an element is a member of the set
bool member(SET *A, int element) {
    return (*A & (1 << element)) != 0;  
}

// Delete an element from the set
void delete(SET *A, int element) {
    *A &= ~(1 << element); 
}

// Union of two sets (A ? B)
SET unionSets(SET *A, SET *B) {
    return *A | *B; 
}

// Intersection of two sets (A n B)
SET intersection(SET *A, SET *B) {
    return *A & *B; 
}

// Difference of two sets (A - B)
SET difference(SET *A, SET *B) {
    return *A & ~(*B); 
}

int main() {
    SET setA, setB;

    initSet(&setA);
    initSet(&setB);


    insert(&setA, 0);
    insert(&setA, 4);
    insert(&setA, 6);
    insert(&setA, 7);


    insert(&setB, 1);
    insert(&setB, 4);
    insert(&setB, 5);
    insert(&setB, 6);


    printf("Set A: ");
    displaySet(&setA);

    printf("Set B: ");
    displaySet(&setB);

    SET setUnion = unionSets(&setA, &setB);
    printf("A U B: ");
    displaySet(&setUnion);

 
    SET setIntersection = intersection(&setA, &setB);
    printf("A n B: ");
    displaySet(&setIntersection);  


    SET setDifference = difference(&setA, &setB);
    printf("(A - B): ");
    displaySet(&setDifference);

    return 0;
}


