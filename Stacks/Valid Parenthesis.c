#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 50

typedef struct {
    char elem[MAX];
    int top; //index of stack top
} Stack;

/*************************************/
/*         HELPER FUNCTIONS          */
/*************************************/
void init(Stack *s);
bool isEmpty(Stack s);
bool isFull(Stack s);
char top(Stack s);
void pop(Stack *s);
void push(Stack *s, char data);
char popReturn(Stack *s);


/*************************************/
/*            YOUR TASK              */
/*************************************/
bool isValidParentheses (char parentheses[]);

int main() {
    char parentheses[256];

    printf("Enter parentheses: ");
    scanf("%s", parentheses);

    printf("The parentheses is %s.", 
        (isValidParentheses(parentheses)) ? "VALID" : "NOT VALID");

    return 0;
}

bool isMatching(char open, char close){
    if((open == '(' &&  close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}')){
        return true;
    }
    else{
        false;
    }
}

bool isValidParentheses (char parentheses[]) {
    Stack temp;
    init(&temp);
    int size = strlen(parentheses);
    int i = 0;
    while(size > i){
        int c = parentheses[i];
        	if(c == '(' || c == '[' || c == '{'){
            push(&temp, c);
       	 }
        	else if(c == ')' || c == ']' || c == '}'){
        		if(isEmpty(temp) || !isMatching(popReturn(&temp), c)){
            	return false;
        	}
    	}
    	 i++;
    }
  
    
    return isEmpty(temp);
}



/*************************************/
/*         HELPER FUNCTIONS          */
/*************************************/
void init(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack s) {
    return (s.top == -1) ? true : false; 
}

bool isFull(Stack s) {
    return (s.top == MAX - 1) ? true : false;
}

char top(Stack s) {
    char d = '\0';
    return (!isEmpty(s)) ? s.elem[s.top] : d;
}

void pop(Stack *s) {
    if(!isEmpty(*s)) {
        s->top--;
    }
}

char popReturn(Stack *s){
    if(!isEmpty(*s)){
        char temp = s->elem[s->top];
        s->top--;
        return temp;
    }
}

void push(Stack *s, char data) {
    if(!isFull(*s)) {
        s->elem[++s->top] = data; 
    }
}
