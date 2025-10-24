#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX (sizeof(unsigned int)* 8)

typedef unsigned int Set;

void initSet(Set *S){
	*S = 0;
}

void insert(Set *S, int data){
	if(data >= 0 && data < MAX){
		*S = *S | (1U << data);
	}
}

void delElem(Set *S, int data){
	*S = *S & ~(1U << data);
}

bool isMember(Set *S, int data){
	if(((1U << data) & *S) != 0){
		return true;
	}
	else{
		return false;
	}
}

Set Union(Set *A, Set *B){
	return *A | *B;
}

Set Intersect(Set *A, Set *B){
	return *A & *B;
}

Set Difference(Set *A, Set *B){
	return *A & ~(*B);
}

int main(){
	Set A;
	Set B;
	initSet(&A);
	initSet(&B);
	insert(&A, 1);
	insert(&A, 4);
	insert(&B, 2);
	insert(&B, 3);
	
	Set C = Union(&A,&B);
	printf("%d", C);
}
