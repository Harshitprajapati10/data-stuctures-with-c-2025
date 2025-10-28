
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
}Node;

// creating the linked list from array
Node* createList(int list[],int length){
    // int length = sizeof(list)/sizeof(list[0]);
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

// Traversing the list

int ListLength(Node *head){
    Node *current = head;
    int count = 0;
    while(current!=NULL){
        count ++;
        current = current->next;
    }
    return count;
}

void printLL(Node *head){
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


//function to create a node
Node* createNode(int data){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

// singly LL insertion
// insert at beginning , insert at mid,insert at end

Node* insertatPosition(Node* head, int data, int position){
    Node* newNode;
    newNode = createNode(data);
    if(position == 1){
        newNode -> next = head;
        return newNode;
    }
    Node* temp = head;
    for (int i = 1; i < position-1 && temp!=NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("position out of range\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp ->next = newNode;
    return head;
}

// deleting a node

Node* deleteNode(Node* head, int position){
    if(position == 1){
        return head->next;
        free(head);
    }
    Node* temp = head;
    for (int i = 1; i < position-1 && temp!= NULL; i++){
        temp = temp->next;
    }
    if(temp==NULL){
        printf("position out of range");
    }
    // free(temp->next);
    temp->next = temp->next->next;
    return head;
}


int main(){
    int LL[] = {3,4,5,32,56,7,8,65,8};
    Node *head;
    head = createList(LL,9);
    printLL(head);
    int length = ListLength(head);
    printf("%d\n\n",length);

    head = insertatPosition(head, 443, 2);
    printLL(head);

    head = insertatPosition(head, 45,1);
    printLL(head);

    head = insertatPosition(head, 666,6);
    printLL(head);

    head = deleteNode(head, 1);
    printLL(head);
    head = deleteNode(head, 5);
    printLL(head);
    head = deleteNode(head, 8);
    printLL(head);

    return 0;
}