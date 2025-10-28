/*

QUEUE-> 
A queue is an ordered list in which insertions are done at one end (rear) and
deletions are done at other end (front). The first element to be inserted is the first one to be
deleted. Hence, it is called First in First out (FIFO) or Last in Last out (LILO) list.


 When an element is inserted in a queue, the concept is called EnQueue, and when an element is
removed from the queue, the concept is called DeQueue.

DeQueueing an empty queue is called underflow and EnQueuing an element in a full queue is
called overflow. Generally, we treat them as exceptions


MAIN OPERTAIONS ->
 --enqueue
 --dequeue

 AUXILIARY OPERATIONS ->
  -- in FRONT()
  -- int queueSize
  -- isQUEUEEMPTY



  implementation OF QUEUE ->
    -- simple simple array
   -- simple circular array
   -- dynamic circular array
   -- linked list 


   // using array enqueue = 1, dequeue = n
   WHY circular array? 
   // using circular array enqueue=1, dequeue = 1


*/


// circular queue using normal array

#include <stdio.h>
#include <stdlib.h>

typedef struct myQueue {
    int *arr;        // dynamic array to store elements
    int front;       // index of front element
    int size;        // current number of elements
    int capacity;    // maximum capacity
} Queue;


Queue* createQueue(int cap) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = cap;
    q->front = 0;
    q->size = 0;
    q->arr = (int*)malloc(cap * sizeof(int));
    return q;
}

void enqueue(Queue* q, int x) {
    if (q->size == q->capacity) {
        printf("Queue is full!\n");
        return;
    }
    int rear = (q->front + q->size) % q->capacity;
    q->arr[rear] = x;
    q->size++;
}


// Remove an element from the front
int dequeue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }
    int res = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return res;
}

// Get the front element
int getFront(Queue* q) {
    if (q->size == 0)
        return -1;
    return q->arr[q->front];
}

// Get the rear element
int getRear(Queue* q) {
    if (q->size == 0)
        return -1;
    int rear = (q->front + q->size - 1) % q->capacity;
    return q->arr[rear];
}

// Free memory
void deleteQueue(Queue* q) {
    free(q->arr);
    free(q);
}

// Driver code
int main() {
    Queue* q = createQueue(5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("%d %d\n", getFront(q), getRear(q)); // 10 30

    dequeue(q);
    printf("%d %d\n", getFront(q), getRear(q)); // 20 30

    enqueue(q, 40);
    printf("%d %d\n", getFront(q), getRear(q)); // 20 40

    // Cleanup
    deleteQueue(q);
    return 0;
}