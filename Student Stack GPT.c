#include <stdio.h>
#include <stdbool.h>
#define MAX 50

typedef struct{
	int id;
	char name[50];
	float gpa;
}Student;

typedef struct{
	Student Students[MAX];
	int top;
}Stack;

void initStack(Stack *s){
	s->top = -1;
}

bool isEmpty(Stack s){
	if(s.top == -1){
		return true;
	}
	else{
		return false;
	}
}

bool isFull(Stack s){
	if(s.top > MAX -1){
		return true;
	}
	else{
		return false;
	}
}

void push(Stack *s, Student data){
	if(!isFull(*s)){
		s->top++;
		s->Students[s->top] = data;
	}
	else{
		printf("Class is FULL");
	}
}

void pop(Stack *s){
	if(!isEmpty(*s)){
		s->top--;
	}
	else{
		printf("Class is EMPTY");
	}
}

void peek(Stack s){
	if(!isEmpty(s)){
		printf("Top student ID: %d Name: %s GPA: %.2f",s.Students[s.top].id, s.Students[s.top].name, s.Students[s.top].gpa);
	}
	else{
		printf("Stack is currently empty");
	}
}

void printStudents(Stack temp){
	Stack s = temp;
	while(s.top != -1){
		
		printf("Student ID: %d Name: %s GPA: %.2f",s.Students[s.top].id, s.Students[s.top].name, s.Students[s.top].gpa);
		printf("\n");
		pop(&s);
	}
}


int main(){
	Stack s1;
	initStack(&s1);
	
	Student student1 = {201, "Charles Boki", 2.4};
	Student student2 = {202, "Charles Boki", 2.4};
	push(&s1, student1);
	push(&s1, student2);
	printStudents(s1);
}
