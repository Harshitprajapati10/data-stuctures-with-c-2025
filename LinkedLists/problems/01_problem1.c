
#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{
    int data;
    struct ListNode *next;
}Node;

// creating the linked list from array
Node* createList(int list[],int length){
    Node *head = NULL;
    Node *temp = NULL;
    Node *tail = NULL;
    for (int i = 0; i < length; i++){
        temp = (Node*)malloc(sizeof(Node));
        temp -> data = list[i];
        temp -> next = NULL;
        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
};

int size(Node *head){
    Node *current = head;
    int count = 0;
    while(current!=NULL){
        count ++;
        current = current->next;
    }
    return count;
}

void display(Node *head){
    Node *current = head;
    while(current != NULL){
        // dont print --> for last node.value
        if(current -> next == NULL){
            printf("%d", current->data);
        }else{
        printf("%d->",current->data);
        }
        current = current-> next;
    }
    printf("\n");
}


Node* createNode(int data){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

// find nth node from the end of linkedlist
Node* nthFromTheEnd(Node* head,int n){
    if(n>size(head)){
        printf("NOT IMPLEMENTABLE");
        return head;
    }
    Node* f = head; Node* s = head;
    for (int i = 0; i < n; i++){
        s = s->next;
    }
    while(s!=NULL){
        s = s->next; f = f->next;
    }
    return f;
}


Node* createCyclicList(){
    /*
        4 -> 2->23 ->1 ->41->49->2->66->54 --|
                        |                   |
                        --------------------

     */
    Node* a = createNode(4); 
    Node* b = createNode(2);
    Node* c = createNode(23);
    Node* d = createNode(1);
    Node* e = createNode(41);
    Node* f = createNode(49);
    Node* g = createNode(2);
    Node* h = createNode(66);
    Node* i = createNode(54);
    a->next = b; b->next =c; c->next =d;d->next = e;
    e->next = f; f->next = g; g->next= h;h->next = i;
    i->next = e;
    return a;
}

// 1 if cycle present else 0
int detectCycle(Node* head){
    Node * f = head; Node* s = head;
    while(f!=NULL){
        s = s->next;
        f = f->next->next;
        if(s==f){
            return 1;
        }
    }return 0;
}

int lengthCycle(Node* head){
    Node * f = head; Node* s = head;
    int sizecycle = 0;
    while(f!=NULL){
        s = s->next;
        f = f->next->next;
        if(s==f){
            break;
        }
    }
    if(f==NULL){
        return sizecycle;
    }
    do{
        f=f->next;
        sizecycle ++;
    } while (f!=s);
    return sizecycle;
}

Node* cycleStartingPoint(Node* head){
    int cyclelength = lengthCycle(head); 
    Node * a = head; Node* b = head;
    for (int i = 0; i < cyclelength; i++){
        a = a->next;
    }
    while(a!=b){
        a = a->next; b = b->next;
    }
    return a;
}




// Insert a node in the sorted linked list

Node* insertInSorted(Node* head, int value){
    /*
    2 -> 5->6 ->8 ->13 ->21->35
    insert = 11
    2 -> 5->6 ->8 ->11 ->13 ->21->35
    */
   Node* newNode = createNode(value);
   if(head->data >= value){
       // insert first
        newNode->next = head;
        return newNode;
   }
   Node* temp = head;
   while(temp != NULL){
        temp = temp->next;
        if(temp->next && temp->next->data >= value){
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        if(!temp->next){ //we're at last node
            temp->next = newNode;
            newNode->next = NULL;
            break;
        }
   }

   return head;
}


// REVERSE LIST
Node* reverseList(Node* head){
    Node* temp = NULL;
    Node* nextNode = NULL;
    while(head){
        nextNode = head->next;
        head->next = temp;
        temp = head;
        head = nextNode;
    }
    return temp;
}

// REVERSElist recursive(TODO: check this function)
/*
Node* reverseListrecursive(Node* head){
    if(head == NULL){
        return NULL;
    }if(head->next == NULL){
        return head;
    }
    Node* secondElem = head->next;
    head->next = NULL;
    Node* reverseRest = reverseListrecursive(secondElem);
    reverseRest->next = head;
    return reverseRest;
}
*/

// find middle of the linked list
Node* findMiddle(Node* head){
    Node* fast = head,*slow = head;
    while(fast->next!= NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }return slow;
}


// display linked list from the end
void printListFromEnd(Node* head){
    if(!head){return;}
    printListFromEnd(head->next);
    printf("%d->",head->data);
}

// check whether a givenLL is odd or even
// if even return 0
int isListEven(Node* head){
    while (head && head->next){
        head = head->next->next;    
    }
    if(!head){ // even
            return 0;
    }return 1; // odd
}

// Bubble sort 
Node* bubbleSort(Node* head) {
    if (!head || !head->next) {
        return head;
    }
    int swapped;
    Node* current;
    Node* last = NULL;
    do {
        swapped = 0;
        current = head;
        while (current->next != last) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);

    return head;
}

// selection sort
Node* selectionSort(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node* start = head;
    while (start != NULL) {
        Node* min = start;
        Node* current = start->next;
        while (current != NULL) {
            if (current->data < min->data) {
                min = current;
            }
            current = current->next;
        }
        if (min != start) {
            int temp = start->data;
            start->data = min->data;
            min->data = temp;
        }
        start = start->next;
    }

    return head;
}



 


int main(){
    // int LL[] = {3,4,5,32,56,7,8,65,8};
    // Node *head;
    // head = createList(LL,9);
    // display(head);

    // printf("%d\n", nthFromTheEnd(head,7)->data);
    // printf("%d\n", nthFromTheEnd(head,1)->data);
    // printf("%d\n", nthFromTheEnd(head,9)->data);
    // printf("%d\n", nthFromTheEnd(head,11)->data);

    // head = createCyclicList();
    // printf("%d\n",detectCycle(head));
    // printf("%d\n",lengthCycle(head));
    // printf("%d\n",cycleStartingPoint(head)->data);

    /*
    int sorted[] = {2,5,6,8,13,21,35};
    Node* head2 = createList(sorted,7);
    display(head2);
    head2 = insertInSorted(head2, 1);
    display(head2);
    head2 = insertInSorted(head2, 8);
    display(head2);
    head2 = insertInSorted(head2, 11);
    display(head2);
    head2 = insertInSorted(head2, 101);
    display(head2);

    head2 = reverseList(head2);
    display(head2);
    */

    int LL[] = {103,94,5,2,56,4,44,3};
    Node *head;
    head = createList(LL,8);
    display(head);
    // Node* MId = findMiddle(head);
    // printf("%d\n",MId->data);
    // printListFromEnd(head);
    //printf("%d\n",isListEven(head)); // 1


    head = selectionSort(head);
    display(head);
    return 0;
}