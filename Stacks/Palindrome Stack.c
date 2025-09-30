#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 128

typedef struct node{
    char elem[MAX];
    int top;
}Stack;

void Push(Stack* S, char x);
void Pop(Stack* S);
char Top(Stack S);
void initStack(Stack* S);

bool isFull(Stack S);
bool isEmpty(Stack S);

// your task is this function!
bool isPalindrome(char palindrome[]);


int main(){
    char palindrome[MAX];
    printf("Enter string: ");
    scanf("%s", palindrome);

    printf("Palindrome? %s", (isPalindrome(palindrome)) ? "Yes!" : "No!");
}

bool isPalindrome(char palindrome[]){
	Stack s1,s2;
	initStack(&s1);
	initStack(&s2);
	
	int i = 0;
	while(palindrome[i] != '\0'){
		Push(&s1, palindrome[i]);
		i++;
	}
	
	Stack temp = s1;
	
	while(!isEmpty(s1)){
		char temp = Top(s1);
		Pop(&s1);
		Push(&s2, temp);
	}
	
	for(int i = temp.top; i > -1;){
		char s1temp = Top(temp);
		char s2temp = Top(s2);	
		Pop(&s2);
		Pop(&temp);
		if(s1temp == s2temp){
			i--;
		}
		else{
			return false;
		}
	}
return true;
	
	
	
 // implement here!!
}

void Push(Stack* S, char x){
    if(isFull(*S) != true){
        S->elem[++S->top] = x;
    }

}

void Pop(Stack* S){
    if(isEmpty(*S) != true){
        S->top--;
    }
}

char Top(Stack S){
    return (isEmpty(S) != true) ? S.elem[S.top] : '\0';
}

void initStack(Stack* S){
    S->top = -1;
}

bool isFull(Stack S){
    return (S.top == MAX - 1) ? true : false;
}
bool isEmpty(Stack S){
    return (S.top == -1) ? true : false;
}


