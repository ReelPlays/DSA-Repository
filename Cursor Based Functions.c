#include <stdio.h>
#define MAX 5

typedef struct{
	char FName[16];
	char LName[24];
	char MI;
}name;

typedef struct{
	name data;
	int link;
}NodeType;

typedef struct{
	NodeType Nodes[MAX];
	int Avail;
}VirtualHeap;

typedef int list;


void initList(VirtualHeap *VH){
	VH->Avail = MAX -1;
	for(int i = 0 ; i < MAX ; i++){
		VH->Nodes[i].link = i-1;
	}
	
}

int allocSpace(VirtualHeap *VH){
	int temp = VH->Avail;
	if(temp != -1){
		VH->Avail = VH->Nodes[temp].link;
	}
	return temp;
}

void insertFirst(VirtualHeap * VH, list * L, name data){
	int temp = allocSpace(VH);
	if(temp != -1){
		VH->Nodes[temp].data = data;
		VH->Nodes[temp].link = *L;
	}
	*L = temp;
}

void insertLast(VirtualHeap * VH, list *L, name data){
	int temp = allocSpace(VH);
	list * trav;
	for(trav = L; *trav != -1; trav = &VH->Nodes[*trav].link){}
	if(temp != -1){
		VH->Nodes[temp].data = data;
		VH->Nodes[temp].link = -1;
	}
	*trav = temp;
}

void printList(VirtualHeap *VH, list L){
	list trav = L;
	while(trav != -1){
		printf("%s ", VH->Nodes[trav].data.FName);
		trav = VH->Nodes[trav].link;
	}
}

void insertSorted(VirtualHeap *VH, list *L, name data){
	list temp = allocSpace(VH);
	list *trav;
	if(temp != -1){
		for(trav = L ; *trav != -1 && VH->Nodes[*trav].data.FName < data.FName ; trav = &VH->Nodes[*trav].link){}
		VH->Nodes[temp].data = data;
		VH->Nodes[temp].link = *trav;
		*trav = temp;
	}
}


int main(){
	VirtualHeap VH;
	list L = -1;
	initList(&VH);
	
	name s1 = {"Keith", "Mark", 'a'};
	name s2 = {"John", "Mark", 'a'};
	name s3 = {"Aohn", "Mark", 'a'};

	insertFirst(&VH,&L,s1);
	insertLast(&VH,&L,s2);
	insertSorted(&VH, &L, s3);
	
	printList(&VH, L);
	
}
