// Linked list implementation

/*
Performance
 Let	n	be	the	number	of	elements	in	the	stack.	The	complexities	for	operations	with	this
 representation	can	be	given	as:
 Space	Complexity	(for	n	push	operations)
 Time	Complexity	of	CreateStack()
 Time	Complexity	of	Push()
 Time	Complexity	of	Pop()
 Time	Complexity	of	Top()
 O(n)
 O(1)
 O(1)	(Average)
 O(1)
 O(1)
 Time	Complexity	of	IsEmptyStack()
 Time	Complexity	of	DeleteStack()
 O(1)
 O(n)
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{
    int data;
    struct ListNode* next;
}Node;


typedef struct Stack{
    Node* top;
} Stack;


Stack* createStack(){
    Stack* S = (Stack*)malloc(sizeof(Stack));
    if(!S){
        printf("Memory allocation failed\n");
        return NULL;
    }
    S->top = NULL;
    return S;
}



int isEmpty(Stack* S){
    return (S->top == NULL);
}

void push(Stack* S, int data){
    Node* temp = (Node*)malloc(sizeof(int));
    if(!temp){
        printf("memory allocation failed\n");
        return;
    }
    temp->data = data;
    temp->next = S->top;
    S->top = temp;
    printf("%d pushed to stack.\n", data);
}

// peek -> return the top value
int peek(Stack* S){
    if(isEmpty(S)){
        printf("Stack is empty.\n");
        return 0;
    }
    return S->top->data;
}

int pop(Stack* S){
    if(isEmpty(S)){
        printf("Stack underflow\n");
        return 0;
    }
    Node* temp = S->top;
    int popped_val = temp->data;
    S->top = S->top->next;
    free(temp);
    return popped_val;
}


// Display stack elements
void display(Stack* S) {
    if (isEmpty(S)) {
        printf("Stack is empty.\n");
        return;
    }
    Node* temp = S->top;
    printf("Stack elements (top → bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    Stack* S = createStack();

    push(S, 10);
    push(S, 20);
    push(S, 30);
    display(S);

    printf("Top element is %d\n", peek(S));
    printf("Popped element: %d\n", pop(S));
    display(S);

    pop(S);
    pop(S);
    pop(S); // should show underflow

    return 0;
}