#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
	int data;
	struct node * link;
}* Nodetype;

typedef Nodetype Dictionary[MAX];

void initDict(Dictionary D){
	for(int i = 0 ; i < MAX ; i++){
		D[i] = NULL;
	}
}

int hash(int data){
	return data % MAX;
}

Nodetype createNode(int data){
	Nodetype temp = malloc(sizeof(struct node));
	if(temp != NULL){
	temp->data = data;
	temp->link = NULL;
	}
	
	return temp;
}

void insert(Dictionary D, int data){
	int val = hash(data);
	Nodetype temp = createNode(data);
	
	Nodetype * trav;
	for(trav = &D[val]; *trav != NULL && (*trav)->data != data; trav = &(*trav)->link){}
	
	if(*trav == NULL){
		*trav = temp;
	}
}

void DeleteElem(Dictionary D, int data){
	int val = hash(data);
	
	Nodetype * trav;
	for(trav = &D[val]; *trav != NULL && (*trav)->data != data; trav = &(*trav)->link){}
	if(*trav != NULL){
		Nodetype  temp = *trav;
		*trav = (*trav)->link;
		free(temp);
	}
	
}

void printDictionary(Dictionary D){
	
	for(int i = 0 ; i < MAX ; i++){
		Nodetype trav = D[i];
		printf("Index %d :", i);
		while(trav != NULL){
			printf(" %d" , trav->data);
			trav = trav->link;
		}
		printf("\n");
	}
}

int main(){
	Dictionary D;
	initDict(D);
	
	insert(D, 1);
	insert(D, 11);
	
	printDictionary(D);
}
