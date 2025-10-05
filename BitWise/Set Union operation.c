#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the linked list node for the set
struct node {
    int data;
    struct node *next;
};

typedef struct node* Set;

// Function to insert an element into a set (no duplicates)
void insert(Set *A, int value) {
    Set curr = *A;

    // check if already exists
    while (curr != NULL) {
        if (curr->data == value)
            return; // already in set
        curr = curr->next;
    }

    // otherwise create new node and add at front
    Set temp = (Set)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->data = value;
        temp->next = *A;
        *A = temp;
    }
}

// Function to print a set
void printSet(Set A) {
    printf("{ ");
    for (Set curr = A; curr != NULL; curr = curr->next) {
        printf("%d ", curr->data);
    }
    printf("}\n");
}

// Your union function
Set Union(Set A, Set B) {
    Set U = NULL;
    Set *trav = &U;

    // Copy all elements from A into U
    for (Set curr = A; curr != NULL; curr = curr->next) {
        Set temp = (Set)malloc(sizeof(struct node));
        if (temp != NULL) {
            temp->data = curr->data;
            *trav = temp;
            trav = &(*trav)->next;
        }
    }

    *trav = NULL;

    // Insert all elements from B into U (avoids duplicates)
    for (Set curr = B; curr != NULL; curr = curr->next) {
        insert(&U, curr->data);
    }

    return U;
}

int main() {
    Set A = NULL;
    Set B = NULL;

    // Build Set A = {1, 2, 3}
    insert(&A, 1);
    insert(&A, 2);
    insert(&A, 3);

    // Build Set B = {3, 4, 5}
    insert(&B, 3);
    insert(&B, 4);
    insert(&B, 5);

    printf("Set A: ");
    printSet(A);
    printf("Set B: ");
    printSet(B);

    // Perform Union
    Set U = Union(A, B);

    printf("Union(A, B): ");
    printSet(U);

    return 0;
}

