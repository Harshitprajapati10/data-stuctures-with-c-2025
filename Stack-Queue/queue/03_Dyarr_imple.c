// use resizeable array
// double the capacity when q is full


#include <stdio.h>
#include <stdlib.h>


typedef struct ArrayQueue{
    int front, rear;
    int capacity;
    int* array;
}Q;

Q* Queue(){
    Q* Q = malloc(sizeof(*Q));
    if(!Q){
        return NULL;
    }
    Q->capacity = 1;
    Q->front = Q->rear = -1; //initially Q is empty
    Q->array = malloc(Q->capacity*sizeof(int));
    if(!Q->array){
        return NULL;
    }
    return Q;
}


int IsEmptyQ(Q* Q){
    return (Q->front == -1);
}

int IsFullQ(Q* Q){
    return ((Q->rear+1) % Q->capacity == Q->front);
}

void ResizeQueue(Q* Q){
    int size = Q->capacity;
    Q->capacity = Q->capacity*2;
    Q->array = realloc(Q->array,Q->capacity* sizeof(int));
    if(!Q->array){
        printf("Memory error");
        return;
    }
    if(Q->front > Q->rear){
        for (int i = 0; i < Q->front; i++){
            Q->array[i+size] = Q->array[i];
        }
    Q->rear = Q->rear+size;
    }
}

void EnQ(Q * Q,int n){
    if(IsFullQ(Q)){
        ResizeQueue(Q);
    }
    
    Q->rear = (Q->rear+1)%Q->capacity;
    Q->array[Q->rear] = n;
    if(Q->front == -1){
        Q->front = Q->rear;
    }
}

int DeQ(Q* Q){
    int data = 0;// return this if Q is empty
    if(IsEmptyQ(Q)){
        printf("Q is Emmpty\n");
        return 0;
    }
    
    data = Q->array[Q->front];
    if(Q->front == Q->rear){
        Q->front = Q->rear = -1;
    }else{
        Q->front = (Q->front + 1)%Q->capacity;
    }

    return data;
}

void DeleteQ(Q* Q){
    if(Q){
        if(Q->array){
            free(Q->array);
        }
        free(Q);   
    }
}

int main(){
    Q* q = Queue();

    EnQ(q, 10);
    EnQ(q, 20);
    EnQ(q, 30);
    EnQ(q, 40);
    EnQ(q, 50);

    printf("Dequeued: %d\n", DeQ(q));
    printf("Dequeued: %d\n", DeQ(q));

    EnQ(q, 60);
    EnQ(q, 70);

    printf("Dequeued: %d\n", DeQ(q));
    printf("Dequeued: %d\n", DeQ(q));
    printf("Dequeued: %d\n", DeQ(q));

    DeleteQ(q);
    return 0;
    return 0;
}


/*
Let n be the number of elements in the queue.
Space Complexity (for n EnQueue operations) O(n)
Time Complexity of EnQueue() O(1) (Average)
Time Complexity of DeQueue() O(1)
Time Complexity of QueueSize() O(1)
Time Complexity of IsEmptyQueue() O(1)
Time Complexity of IsFullQueue() O(1)
Time Complexity of QueueSize() O(1)
Time Complexity of DeleteQueue() O(1)
*/