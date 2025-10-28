#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
    struct ListNode *prev;
}Node;


int size(Node* head){
    Node* temp = head;
    int size = 0;
    while(temp!=NULL){
        size++;
        temp = temp->next;
    }return size;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        if(temp -> next == NULL){
            printf("%d", temp->data);
        }else{
        printf("%d <--> ",temp->data);
        }
        temp = temp->next;
    }printf("\n");
}

// create LL and return head
Node* createList(int list[], int size){
     Node *head = NULL;
     Node *temp = NULL;
     Node *tail = NULL;
     for (int i = 0; i < size; i++){
        temp = (Node*)malloc(sizeof(Node));
        temp -> data = list[i];
        temp -> next = NULL;
        if(head == NULL){
            head = temp;
            head->prev = NULL;
            tail = temp;
        }else{
            tail->next = temp;
           // temp->prev = tail;
            tail = temp;
        }
    }
    return head;
}

// function to createNode
Node* createNode(int data){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insertion in DLL
Node* insertAtposition(Node* head, int position, int value){
    // out of bound insertion
    if(position > size(head)+1){;
        printf("Wrong position to insert\n");
        return head;
    }
    Node* newNode = createNode(value);
    // Insertion at first position
    if(position == 1){
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    Node* temp = head;
    for (int i = 1; i < position-1 && temp!=NULL; i++){
        temp = temp->next;
    }

    // if(!temp->next){
    //     //insertion at last position
    //     newNode->prev = temp;
    //     temp->next = newNode;
    // }
    
    newNode->prev = temp;
    if(temp->next){ //for non lastnodes
        temp->next->prev = newNode;
        newNode->next = temp->next;
    }
    temp->next = newNode;
    return head;
}


//deleting any node

Node* deleteNode(Node* head, int position){
    if(position == 1){
        head->next->prev = NULL;
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
    if(!temp->next->next){ // for last node
        temp->next =NULL;
        return head;
    }
    temp->next = temp->next->next;
    temp->next->prev = temp;
    return head;
}



int main(){
    int LL[] = {3,4,5,32,56,7,8,65,8};
    Node *head;
    head = createList(LL,9);
    display(head);
    printf("%d\n",size(head));
    head = insertAtposition(head,1,34);
    display(head);
    head = insertAtposition(head,11,734);
    display(head);
    head = insertAtposition(head,6,14);
    display(head);
    head = deleteNode(head,1);
    display(head);
    head = deleteNode(head,6);
    display(head);
    head = deleteNode(head,9);
    display(head);
    head = deleteNode(head,9);
    display(head);
    return 0;
}