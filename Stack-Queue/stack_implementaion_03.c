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

//TODO->
typedef struct ListNode{
    int data;
    struct ListNode* next;
}Node;

