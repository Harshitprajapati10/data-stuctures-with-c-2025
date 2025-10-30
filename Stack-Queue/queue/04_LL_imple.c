// linked list implementaion of c

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Q;;

Q* CreateQueue(){
    Q* Q = malloc(sizeof(*Q));
    if(!Q){
        return NULL;
    }
    Node* temp = malloc(sizeof(Node));
    Q->front = Q->rear = NULL;
    return Q;
}

int isEmptyQueue(Q* Q){
    return (Q->front == NULL);// True =1
}

void EnQ(Q* Q, int data){
    Node* newNode = malloc(sizeof(Node));
    if(!newNode){
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if(Q->rear){
        Q->rear->next = newNode;
    }
    Q->rear = newNode;
    if(Q->front == NULL){
        Q->front = Q->rear;
    }
}

int DeQ(Q* Q){
    int data = 0;
    Node* temp;
    if(isEmptyQueue(Q)){
        printf("Q is empty");
        return 0;
    }
    temp = Q->front;
    data = Q->front->data;
    Q->front = Q->front->next;
    free(temp);

    return data;
}

int main(){
    Q* q = CreateQueue();

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

    
    return 0;
    return 0;
}
