#include <stdio.h>
#include <stdlib.h>

#define VHSIZE 50

typedef struct {
    int data;
} Element;

typedef struct {
    Element elem;
    int next;
} Node;

typedef struct {
    Node VHNode[VHSIZE];
    int avail;
} VHeap;

typedef int Stack;  // index of top element


/*************************************/
/*           YOUR TASKS              */
/*************************************/
// --- CB functions --- //
void initVHeap(VHeap *VH);
int allocSpace(VHeap *VH);
void freeSpace(VHeap *VH, int idx);

// --- Stack functions ---
void initStack(Stack *S);
void insertSorted(VHeap *VH, Stack *S, int data);
void printStack(VHeap VH, Stack S);

// --- Main program ---
int main() {
    VHeap VH;
    Stack S;
    int N, val;

    initVHeap(&VH);
    initStack(&S);

    printf("Enter size: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        insertSorted(&VH, &S, val);
    }

    printStack(VH, S);

    return 0;
}

void initVHeap(VHeap *VH) {
    VH->avail = VHSIZE - 1;
    for(int i = 0 ; i < VHSIZE; i++){
        VH->VHNode[i].next = i-1;
    }
}

int allocSpace(VHeap *VH) {
    int temp = VH->avail;
    if(temp != -1){
        VH->avail = VH->VHNode[temp].next;
    }
    return temp;
}

void freeSpace(VHeap *VH, int idx) {

    VH->VHNode[idx].next = VH->avail;
    VH->avail = idx;
}

// --- Stack functions ---
void initStack(Stack *S) {
    *S = -1;
}

void insertSorted(VHeap *VH, Stack *S, int data) {
    Stack * trav;
    int temp = allocSpace(VH);
    for(trav = S; *trav != -1 && VH->VHNode[*trav].elem.data < data; trav = &VH->VHNode[*trav].next){}
    	VH->VHNode[temp].elem.data = data;
    	VH->VHNode[temp].next = *trav;
    	*trav = temp;

}

void printStack(VHeap VH, Stack S) {
    // Implementation here...
    Stack temp = S;
    while(temp != -1){
    	printf("%d", VH.VHNode[temp].elem.data);
    	temp = VH.VHNode[temp].next;
	}
}
