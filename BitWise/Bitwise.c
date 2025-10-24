#include <stdio.h>
#define MAX 10

typedef int SET[MAX];

void initSet(SET S){
	int i = 0;
	for(int i = 0; i < MAX ; i++){
		S[i] = 0;
	}
}

void populateSet(SET S, int data[]){
	for(int i = 0 ; i < MAX ; i++){
		int x = data[i];
		S[x] = 1;
	}
}

SET * UNION(SET A, SET B){
	SET *C = malloc(sizeof(SET));
	int i = 0;
	for(i = 0 ; i < MAX ; i++){
		if(A[i] == 1 || B[i] == 1){
			(*C)[i] = 1;
		}
		else{
			(*C)[i] = 0;
		}
	}
	return C;
}

void printSet(SET S){
	for(int i = 1 ; i < MAX ; i++){
		printf("%d ", i);
		if(S[i] != 0){
		
		printf("- %d", S[i]);
		}
		else{
		printf("- 0");
		}
		printf("\n");
	}
}

int main(){
	
	SET A = {};
	SET B = {};
	
	initSet(A);
	initSet(B);
	
	int data[MAX] = {3,5,7,9,4};
	int data1[MAX] = {1,2,6,8};
	
	populateSet(A, data);
	populateSet(B, data1);
	SET * U = UNION(A,B);
	printSet(*U);
	

}
