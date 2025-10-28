#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode* next;
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
    tail->next = head; // for CLL
    return head;
};

void display(Node* head){
    if(head==NULL){
        printf("EMPTY LIST\n");
        return;
    }
    Node *dummy = head;
    do{
        printf("%d->",dummy->data); 
        dummy = dummy->next; 
    }while(dummy!= head);
    printf("%d >\n",head->data);
}

int length(Node* head){
    if(head==NULL){
        return 0;
    }
    int count = 0;
    Node* dummy = head;
    do{
        count++;
        dummy = dummy->next;
    }while(dummy!=head);
    return count;
}

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(newNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//Inserting a node at the end of CLL return head
Node* insertatend(Node* head,int value){
    Node* newNode = createNode(value);
    if(head == NULL){ // If LL is empty
        newNode->next = newNode;
        return newNode;
    }
    Node* temp = head;
    newNode->next = head;
    while (temp->next!=head){ //traverse till last node
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Inserting a node at front of CLL
Node* insetatfront(Node* head, int value){
    Node* newNode = createNode(value);
    if(head == NULL){
        newNode->next = newNode;
        return newNode;
    }
    Node* temp = head;
    newNode->next = head;
    while (temp->next!=head){
        temp = temp->next;
    }
    temp->next = newNode;
    return newNode; // only diff in insert at end
}

// Insert at specific position
Node* insert(Node* head, int positon, int value){
    Node* newNode = createNode(value);
    if(head == NULL){
        newNode->next = newNode;
        return newNode;
    }
    Node* temp = head;
    for (int i = 1; i < positon-1; i++){
       temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// deletelast
Node* deleteLast(Node* head){
    if(head == NULL){
        printf("Empty List\n");
        return head;
    }
    Node* temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    free(&(temp->next));
    temp->next = temp->next->next;
    return head;
}

Node* deleteFirst(Node* head){
    if(head == NULL){
        printf("Empty List\n");
        return head;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    free(&(temp->next));
    temp->next = temp->next->next;
    return temp->next;
}

Node* delete(Node* head, int position){
    if(head == NULL){
        printf("Empty List\n");
        return head;
    }
    Node* temp = head;
    for (int i = 1; i < position-1; i++){
        temp = temp->next;
    }
    free(&(temp->next));
    temp->next = temp->next->next;
    return head;
}

int main(){
    int LL[] = {3,4,5,32,56,7,8,65,8};
    Node *head;
    head = createList(LL,9);
    display(head);
    head = insertatend(head,12);
    display(head);
    head = insetatfront(head,19);
    display(head);
    head = insert(head,5,21);
    display(head);
    head = deleteLast(head);
    display(head);
    head = deleteFirst(head);
    display(head);
    head = delete(head,5);
    display(head);
    printf("%d\n",length(head));
}