#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char elem;
	struct node *link;
}node;

typedef struct{
	node *top;
}Stack;

void initStack(Stack *s){
	s->top = NULL;
}

void push(Stack *s,int x){
	node *temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->elem = x;
		temp->link = NULL;
		temp->link = s->top;
		s->top = temp;
	}
	else{
		printf("Malloc Failed");
	}
}

void pop(Stack *s){
	if(s->top != NULL){
		node *temp = s->top;
		s->top = s->top->link;
		free(temp);
	}
}

void top(Stack *s){
	printf("%c ", s->top->elem);
}


void printStack(Stack s){
	
	while(s.top != NULL){
		top(&s);
		pop(&s); 
	}
}

char popReturn(Stack *s){
	char data;
	if(s->top != NULL){
		node *temp = s->top;
		s->top = s->top->link;
		data = temp->elem;
		free(temp);
	}
	return data;
}


int main(){
	Stack s1;
	initStack(&s1);
	
	push(&s1,'a');
	push(&s1,'b');
	push(&s1,'c');
//	printStack(s1);
	popReturn(&s1);
	printStack(s1);
	
}
