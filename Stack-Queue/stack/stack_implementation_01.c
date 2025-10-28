/*
DEFINITION -> A stack is an ordered list in which insertion and deletion are done at one end, called top. The last element inserted is the first one to be deleted. Hence it is called LIFO, FILO list.

PUSH -> When an element is inserted in stack
POP-> when an element is removed from the stack
underflow -> trying to pop empty stack
overflow -> trying to push in full stack


Stack ADT(Absract data type)
- following operation made stack ADT
    - Main operations
    * push(int data) * pop()
    -Auxiliart stack operations
    * int Top() - return last inserted element without popping
    * int Size() - return no. of elements in a stack
    * int isEmptyStack() -indicates stack is empty or not
    * int IsFullStack() -> INdicates whether the stack is full or not
    
    EXCEPTIONS -> IN stack ADT, Attempting	the
    execution	of	pop	(top)	on	an	empty	stack	throws	an	exception.	Trying	to	push	an	element	in	a	full
    stack	throws	an	exception.

*/

/*
IMPLEMENTATION OF STACK ADT
-simple array based
-dynamic array based
- linked lists 
*/

//simple array based implementation

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef struct ArrayStack{
    int top;
    int capacity;
    int *Array;
}Stack;

Stack* createStack(){
    Stack* S = malloc(sizeof(Stack));
    if(!S){
        return NULL;
    }
    S->capacity = MAXSIZE;
    S->top = -1;
    S->Array = malloc(S->capacity*sizeof(int));
    if(!S->Array){
        return NULL;
    }
    return S;
}

int IsEmptyStack(Stack* S){
    return (S->top == -1); // 1 if this is true
}

int IsFullStack(Stack* S){
    return (S->top == S->capacity -1);
}

void push(Stack* S, int data){
    if(IsFullStack(S)){
        printf("Stack Overflow\n");
    }
    else{
        S->Array[++S->top] = data;
    }
}

int pop(Stack* S){
    if(IsEmptyStack(S)){
        printf("Stack underflow\n");
        return 00;
    }
    else{
        return (S->Array[S->top--]);
    }
}

void ShowStack(Stack* S){
    printf("Top is: %d >  ", S->top);
    if(S->top == -1){
        printf("Empty Stack\n");
    }
    if(S->top >= 0 && S->top <= S->capacity){
        for (int i = 0; i < S->top; i++){
        printf("%d |", S->Array[i]);   
    } 
        printf("\n");  
    }
    if(S->top >= S->capacity){
        printf("Full stack\n");
    }
    
}

int main(){
    Stack* stack = createStack();
    ShowStack(stack);
    push(stack, 12);
    push(stack, 12);
    push(stack, 12);
    push(stack, 12);
    push(stack, 12);
    push(stack, 12);
    push(stack, 12);
    push(stack, 12);
    push(stack, 12);
    push(stack, 12);
    // push(stack, 12);
    ShowStack(stack);
    printf("%d\n",IsFullStack(stack)); //1

    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    ShowStack(stack);

    printf("%d\n",IsEmptyStack(stack));//1
    // pop(stack);
    // push(stack, 12);
   
    
    
    return 0;
} 

/*
 Space	Complexity	(for	n	push	operations)
 Time	Complexity	of	Push()
 Time	Complexity	of	Pop()
 Time	Complexity	of	Size()
 Time	Complexity	of	IsEmptyStack()
 Time	Complexity	of	IsFullStackf)
 O(n)
 O(1)
 O(1)
 O(1)
 O(1)
 O(1)
 Time	Complexity	of	DeleteStackQ
 Limitations
 O(1)
 The	maximum	size	of	the	stack	must	first	be	defined	and	it	cannot	be	changed.	Trying	to	push	a
 new	element	into	a	full	stack	causes	an	implementation-specific	exception
*/