#include <stdio.h>
#include <stdlib.h>

typedef enum {
    TRUE,
    FALSE
} boolean;

typedef struct node {
    int data;
    struct node *next;
} *List;

/*************************************/
/*           YOUR TASKS              */
/*************************************/
boolean isEqualNotSorted(List A, List B);
boolean isEqualSorted(List A, List B);
void sort(List *L);


/*************************************/
/*       PROVIDED FUNCTIONS          */
/*************************************/
void initList(List *L);
void insertFirst(List *L, int data);
void deleteFirst(List *L);
void populate(List *L, int size);
void printList(List L);
void freeAll(List *L);

int main() {
    List A, B;
    int sizeA, sizeB;

    initList(&A);
    initList(&B);

    printf("Enter size of List A: ");
    scanf("%d", &sizeA);
    populate(&A, sizeA);

    printf("\nEnter size of List B: ");
    scanf("%d", &sizeB);
    populate(&B, sizeB);

    printf("\nBefore Sorting:\n");
    printf("List A: ");
    printList(A);
    printf("List B: ");
    printList(B);

    printf("NOT SORTED: %s\n", (isEqualNotSorted(A, B) == TRUE) ? "EQUAL" : "NOT EQUAL");

    sort(&A);
    sort(&B);

    printf("\nAfter Sorting:\n");
    printf("List A: ");
    printList(A);
    printf("List B: ");
    printList(B);

    printf("SORTED: %s", (isEqualSorted(A, B) == TRUE) ? "EQUAL" : "NOT EQUAL");

    freeAll(&A);
    freeAll(&B);

    return 0;
}

boolean isEqualNotSorted(List A, List B) {
   	sort(&A);
   	sort(&B);
   	return isEqualSorted(A,B);
   }

boolean isEqualSorted(List A, List B) {
    while(A != NULL && B != NULL){
        if(A->data == B->data){
            A = A->next;
            B = B->next;
        }
        else{
            return FALSE;
        }
    }
    if(A == NULL && B == NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void sort(List *L) {
    List *index, *jndex;
    int temp;
    for(index = L; *index != NULL ; index = &(*index)->next){
        for(jndex = &(*index)->next ; *jndex != NULL ; jndex = &(*jndex)->next){
        	if((*index)->data > (*jndex)->data){
            temp = (*index)->data;
            (*index)->data = (*jndex)->data;
            (*jndex)->data = temp;
            
			}
        }
    }
}

void initList(List *L) {
    *L = NULL;
}

void insertFirst(List *L, int data) {
    List temp = (List)malloc(sizeof(struct node));
    
    if(temp != NULL) {
        temp->data = data;
        temp->next = *L;
        *L = temp;
    }
}

void deleteFirst(List *L) {
    if(*L != NULL) {
        List temp = *L;
        *L = temp->next;
        free(temp);
    }
}

void populate(List *L, int size) {
    for(int i = 0; i < size; i++) {
        int temp;
        printf("Enter number %d: ", i + 1);
        scanf("%d", &temp);
        insertFirst(L, temp);
    }
}

void printList(List L) {
    if(L == NULL) {
        printf("EMPTY");
    }

    for(List curr = L; curr != NULL; curr = curr->next) {
        printf("%d ", curr->data);
    }

    printf("\n");
}

void freeAll(List *L) {
    List del;

    while(*L != NULL) {
        del = *L;
        *L = (*L)->next;
        free(del);
    }
}

