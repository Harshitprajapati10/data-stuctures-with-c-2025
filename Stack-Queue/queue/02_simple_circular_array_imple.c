// circular array implementaion of a queue


#include <stdio.h>
#include <stdlib.h>


typedef struct ArrayQueue{
    int front, rear;
    int capacity;
    int* array;
}Q;

Q* Queue(int size){
    Q* Q = malloc(sizeof(Q));
    if(!Q){
        return NULL;
    }
    Q->capacity = size;
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

void EnQ(Q * Q,int n){
    if(IsFullQ(Q)){
        printf("Q overflow\n");
    }
    else{
        Q->rear = (Q->rear+1)%Q->capacity;
        Q->array[Q->rear] = n;
        if(Q->front == -1){
            Q->front = Q->rear;
        }
    }
}


int DeQ(Q* Q){
    int data = 0;// return this if Q is empty
    if(IsEmptyQ(Q)){
        printf("Q is Emmpty\n");
        return 0;
    }
    else{
        data = Q->array[Q->front];
        if(Q->front == Q->rear){
            Q->front = Q->rear = -1;
        }else{
            Q->front = (Q->front + 1)%Q->capacity;
        }
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
    Q* q = Queue(5);

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
Performance: Let n be the number of elements in the queue:
Space Complexity (for n EnQueue operations) O(n)
Time Complexity of EnQueue() O(1)
Time Complexity of DeQueue() O(1)
Time Complexity of IsEmptyQueue() O(1)
Time Complexity of IsFullQueue() O(1)
Time Complexity of QueueSize() O(1)
Time Complexity of DeleteQueue() O(1)
Limitations: The maximum size of the queue must be defined as prior and cannot be changed.
Trying to EnQueue a new element into a full queue causes an implementation-specific exception
*/