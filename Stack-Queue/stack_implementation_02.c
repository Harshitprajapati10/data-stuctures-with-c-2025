// dynamic array based implementation

// use dynamically (arraylist) to do so
// If	the	array	is	full,	create	a new	array	of	twice	the	size,	and	copy	the	items.	With	this	approach,	pushing	n	items	takes	time proportional	to	nlets see

/*
How n 

for 32 pushes we want to double size of array log32(=5) times ; at n=1 we do copy operation 1 time, at n=2 we do copy operation 2 times .....
while n = 32 we do copy operations 1+2+4+8+16 = 31, which is approx.equal to 32. 
WE ARE DOING DOUBLIG OPERATION logn times

THE TOTAL TIME IS = 

T(n) = 1+2+4+8+....n/4 +n/2 +n
     =  n(1+1/2+1/4+....4/n+2/n+1/n)
     = as n->inf
     = O(n)
T(n) is O(n) and amortized time of a push operation is O(1)




Performance-->

 Let	n	be	the	number	of	elements	in	the	stack.	The	complexities	for	operations	with	this
 representation	can	be	given	as:
 Space	Complexity	(for	n	push	operations)
 Time	Complexity	of	CreateStack()
 Time	Complexity	of	PushQ
 Time	Complexity	of	PopQ
 Time	Complexity	of	Top()
 Time	Complexity	of	IsEmpryStackf)
  Time	Complexity	of	IsFullStackf)
 Time	Complexity	of	DeleteStackQ
 O(n)
 O(1)
 O(1)	(Average)
 O(1)
 O(1)
 O(1))
 O(1)
 O(1))

 Note:	Too	many	doublings	may	cause	memory	overflow	exceptio
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArrayStack{
    int top;
    int capacity;
    int * Array;
}Stack;

Stack* createStack(){
    Stack* S = malloc(sizeof(Stack));
    if(!S){
        return NULL;
    }
    S->capacity = 1;
    S->top = -1;
    S->Array = malloc(S->capacity*sizeof(int));
    if(!S->Array){
        return NULL;
    }
    return S;
}

int IsFullStack(Stack* S){
    return (S->top == S->capacity -1);
}

void DoubleStack(Stack* S){
    S->capacity *= 2;
    S->Array = realloc(S->Array, S->capacity*sizeof(int));
}

void push(Stack* S, int data){
    // no overflow in this
    if(IsFullStack(S)){
        DoubleStack(S);
    }
    S->Array[++S->top] = data;
}


int IsEmptyStack(Stack* S){
    return (S->top == -1); // 1 if this is true
}

int Top(Stack* S){
    if(IsEmptyStack(S)){
        return 000;
    }
    return S->Array[S->top];
}

int pop(Stack* S){
    if(IsEmptyStack(S)){
        return 000;
    }
    return S->Array[S->top--];
}

void DeleteStack(Stack* S){
    if(S){
        if(S->Array){
            free(S->Array);
        }
        free(S);
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
    printf("%d\n",IsEmptyStack(stack));
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
    printf("%d\n",IsFullStack(stack));

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

    printf("%d\n",IsEmptyStack(stack));
    return 0;
}