#include <stdio.h>
#define MAX 5

typedef struct node{
	int data;
	int link;
}Nodetype;

typedef struct{
	Nodetype Nodes[MAX];
	int Avail;
}VirtualHeap;

typedef int list;

void initVHeap(VirtualHeap *VH){
	int i = 0;
	VH->Avail = MAX - 1;
	for(i = 0 ; i < MAX ; i++){
		VH->Nodes[i].link = i - 1;
	}
}

int allocSpace(VirtualHeap *VH){
	int temp = VH->Avail;
	if(temp != -1){
		VH->Avail = VH->Nodes[temp].link;
	}
	return temp;
}

void insertFirst(VirtualHeap *VH, list *L, int data){
	int temp = allocSpace(VH);
	if(temp != -1){
		VH->Nodes[temp].data = data;
		VH->Nodes[temp].link = *L;	
	}
	*L = temp;
}

void insertLast(VirtualHeap *VH, list *L, int data){
	int temp = allocSpace(VH);
	list * trav;
	for(trav = L; *trav != -1; trav = &VH->Nodes[*trav].link){}
	if(temp != -1){
		VH->Nodes[temp].data = data;
		VH->Nodes[temp].link = -1;
	}
	*trav = temp;
}

void insertLastUnique(VirtualHeap *VH, list *L, int data){
	int temp = allocSpace(VH);
	list * trav;
	for(trav = L; *trav != -1 && VH->Nodes[*trav].data != data; trav = &VH->Nodes[*trav].link){}
	if(*trav != -1){
		VH->Nodes[temp].data = data;
		VH->Nodes[temp].link = -1;
	}
	*trav = temp;
}

int main(){
	
}
