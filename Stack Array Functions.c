#include <stdio.h>
#include <stdbool.h>
#define MAX 5


typedef struct{
	char data[MAX];
	int top;
}Stack;

void initStack(Stack *s){
	s->top = -1;
}

bool isEmpty(Stack *s){
	if(s->top == -1){
		return true;
	}
	else{
		return false;
	}
}

bool isFull(Stack *s){
	if(s->top > MAX){
		return true;
	}
	else{
		return false;
	}
}

void push(Stack *s, char data){
	if(!isFull(s)){
		s->data[s->top] = data;
		s->top++;
	}
}

void pop(Stack *s){
	if(!isEmpty(s)){
		s->top--;
	}
}

int top(Stack *s){
	if(!isEmpty(s)){
		return s->data[s->top];
	}
}

int main(){
	
}
