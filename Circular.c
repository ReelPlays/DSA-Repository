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
    // test
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
			int var = Top(q);
			Dequeue(q);
			printf("%d", var);
		}
	}
}

void EnqueueSorted(Queue *q, int x) {
    Queue temp;
    initQueue(&temp);
    int var;

    // Case 1: empty queue
    if (isEmpty(*q)) {
        Enqueue(q, x);
        return;
    }

    // Case 2: move until correct position
    while (!isEmpty(*q)) {
        var = Top(q);
        Dequeue(q);

        if (var > x) {
            Enqueue(&temp, x);   // insert x before the bigger element
            // put current element too
            Enqueue(&temp, var);
            break;  // stop checking, just move the rest
        } else {
            Enqueue(&temp, var);
        }
    }

    // Move the rest of q into temp
    while (!isEmpty(*q)) {
        Enqueue(&temp, Top(q));
        Dequeue(q);
    }

    // If x is bigger than all, it wasn’t inserted yet ? put it at end
    if (Bottom(&temp) < x) {   // Rear() = last element accessor
        Enqueue(&temp, x);
    }

    // Copy back
    while (!isEmpty(temp)) {
        Enqueue(q, Top(&temp));
        Dequeue(&temp);
    }
}


int main(){
	Queue q1;
	initQueue(&q1);
	
	Queue q2;
	initQueue(&q2);
	int var;
	Node s1 = {1,2,3,4,5};
	Node s2 = {3,2,1,4,5};
	
	EnqueueSorted(&q2, s2.data[0]);
	EnqueueSorted(&q2, s2.data[1]);
	EnqueueSorted(&q2, s2.data[2]);
	EnqueueSorted(&q2, s2.data[3]);
	EnqueueSorted(&q2, s2.data[4]);
	
	printOrder(&q2);

	

//	for(int i = 0 ; i < 5 ; i++){
//		var = Top(&q1);
//			printf("%d\n", var);
//			Dequeue(&q1);
//	}
	
	
	
	
}
