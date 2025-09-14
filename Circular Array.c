#include <stdio.h>
#include <stdbool.h>
#define MAX 9


typedef struct{
	int elem;
}Elem;

typedef struct{
	Elem elements[MAX];
	int front;
	int rear;
}Queue;

void initQueue(Queue *q){
	q->front = 0;
	q->rear = MAX -1;
}

bool isFull(Queue q){
	if(q.front == (q.rear + 2) % MAX){
		return true;
	}
	else{
		return false;
	}
}

bool isEmpty(Queue q){
	if(q.front == (q.rear + 1) % MAX){
		return true;
	}
	else{
		return false;
	}
}

void Enqueue(Queue *q, Elem x){
	if(!isFull(*q)){
		q->rear = (q->rear + 1) % MAX;
		q->elements[q->rear] = x;
	}
}

void Dequeue(Queue *q){
	if(!isEmpty(*q)){
		q->front = (q->front + 1) % MAX;
	}
}

Elem returnDequeue(Queue *q){
	Elem temp;
	if(!isEmpty(*q)){
		temp = q->elements[q->front];
		q->front = (q->front + 1) % MAX;
	}
	printf("%d", temp.elem);
	return temp;
}



int main(){
	Queue q1, q2;
	initQueue(&q1);
	initQueue(&q2);
	
	
	int size;
	int temp;
	Elem q;
	
	printf("Enter how many elements");
	scanf("%d", &size);
	Elem elems[size];
	
	printf("Enter the elements: \n");
	
	for(int i = 0 ; i < size ; i++){ //Enqueues a user specified count of struct elements
		scanf("%d", &temp);
		q.elem = temp;
		Enqueue(&q1, q);
		
	}
		
	printf("Queue 1 Elements: \n");
	
	
	for(int i = 0 ; i < size ; i++){
		Enqueue(&q2, returnDequeue(&q1));   // This returns the Enqueued struct then re Enqueued to another Queue
	}										// Dequeued from q1 then re-Enqueued to q2
  
    
    printf("\nTransfered to Queue 2\n: ");

  
	returnDequeue(&q2);
    returnDequeue(&q2);
    returnDequeue(&q2);
    returnDequeue(&q2);
    returnDequeue(&q2);
    
    

	
	
	
	
}
