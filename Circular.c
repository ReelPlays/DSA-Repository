#include <stdio.h>
#include <stdbool.h>
#define MAX 6


typedef struct{
	int data[MAX];
}Node;

typedef struct{
	Node data;
	int front;
	int rear;
}Queue;

void initQueue(Queue *s){
	s->front = 0;
	s->rear =  MAX - 1;
}

bool isEmpty(Queue s){
	if((s.rear + 1) % MAX == s.front){
		return true;
	}
	else{
		return false;
	}
}

bool isFull(Queue s){
	if((s.rear + 2) % MAX == s.front){
		return true;
	}
	else{
		return false;
	}
}

void Enqueue(Queue *s, int data){
	if(!isFull(*s)){
		s->rear = (s->rear + 1 ) % MAX;
		s->data.data[s->rear] = data;
	}
}

void Dequeue(Queue *s){
	if(!isEmpty(*s)){
		s->front = (s->front +1 )% MAX;
	}
}

int Top(Queue *s){
	if(!isEmpty(*s)){
		return s->data.data[s->front];
	}
}

int Bottom(Queue *s){
	if(!isEmpty(*s)){
		return s->data.data[s->rear];
	}
}

int FindElemAgain(Queue *q, int x){
	
	Queue temp;
	initQueue(&temp);
	temp = *q;
	 //creates a copy of the queue so it wont be affected during Dequeueing
	int var;
	int countOfElem = (temp.rear - temp.front + MAX) % MAX +1;  // Calculates how many elements there are in the Queue
	if(!isEmpty(temp)){
		for(int i = 0 ; i < countOfElem ; i++){
			var = Top(&temp);
			if(var == x){
				return var;
			}
			else{
				Dequeue(&temp);
			}
		}
		
	}
	return -1;
}

int FindElem(Queue *temp, int x){
    Queue q;
    initQueue(&q);
    q = *temp; 
    
    int var;
    int count = (q.rear - q.front + MAX) % MAX + 1; 
    
    
    for(int i = 0; i < count; i++){
        var = Top(&q);
        if(var == x){
            return var; 
        }
        Dequeue(&q);
    }
    
    return -1; 
}

void printOrdered(Queue *q){
    if(!isEmpty(*q)){
        int i = q->front;
        while(i != (q->rear + 1) % MAX){
            printf("%d  ", q->data.data[i]);
            i = (i + 1) % MAX;
        }
    }
    printf("\n");
}

void printOrder(Queue *q){
	if(!isEmpty(*q)){
		int i;
		for(i = q->front ; i != (q->rear + 1)% MAX; i = (i+1)% MAX){
			printf("%d");
		}
	}
}



int main(){
	Queue q1;
	initQueue(&q1);
	int var;
	Node s1 = {1,2,3,4,5};
	
	Enqueue(&q1, s1.data[0]);
	Enqueue(&q1, s1.data[3]);
	Dequeue(&q1);
	
	
	
	for(int i = 0 ; i < 5 ; i++){
		Enqueue(&q1, s1.data[i]);
		var = Bottom(&q1);
			printf("%d\n", var);
		 
	}


	
	printOrder(&q1);

int elem = FindElemAgain (&q1, 4);
printf("Found %d",elem);

//	for(int i = 0 ; i < 5 ; i++){
//		var = Top(&q1);
//			printf("%d\n", var);
//			Dequeue(&q1);
//	}
	
	
	
	
}
