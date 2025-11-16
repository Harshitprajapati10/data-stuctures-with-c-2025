#include <stdio.h>
#include <stdlib.h>

// struct bt
typedef struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
}TreeNode;


TreeNode* createNode(int value){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// create the binary tree
void populate(TreeNode **node){
    int value;
    printf("Enter the value of this node: ");
    scanf("%d",&value);
    *node = createNode(value);

    char choice;
    printf("Do you want to enter left of &d? (y,n): ",value);
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y'){
        populate(&((*node)->left));
    }

    printf("Do you want to enter right of &d? (y,n): ",value);
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y'){
        populate(&((*node)->right));
    }
}


// display the binary tree
void display(TreeNode *node, int level) {
    if (node == NULL) return;
    for (int i = 0; i < level; i++) printf("\t");
    printf("%d\n", node->data);
    display(node->left, level + 1);
    display(node->right, level + 1);
}

// prettydisplay
void prettyDisplay(TreeNode *node, int level) {
    if (node == NULL) return;
    prettyDisplay(node->right, level + 1);
    if (level != 0) {
        for (int i = 0; i < level - 1; i++) printf("|\t\t");
        printf("|------->%d\n", node->data);
    } else {
        printf("%d\n", node->data);
    }
    prettyDisplay(node->left, level + 1);
}



// pre order traversal
// node -> left ->right
void preOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}


//IN order traversal
// L,N,R
void inOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

//post order traversal
// L<R<N
void postOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}


// bfs in tree/ level order traversal
// using a queue

typedef struct Queue{
    TreeNode** arr;
    int front;
    int rear;
    int capacity;
}Queue;
Queue* createQueue(int capacity){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (TreeNode**)malloc(capacity * sizeof(TreeNode*));
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    return q;
}
int isEmpty(Queue* q) {
    return q->front == q->rear;
}
void enqueue(Queue* q, TreeNode* node) {
    if (q->rear == q->capacity) return;
    q->arr[q->rear++] = node;
}
TreeNode* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    return q->arr[q->front++];
}

void BFS(TreeNode* root){
    if(root==NULL){
        return;
    }
    Queue* q = createQueue(100);
    enqueue(q,root);
    printf("BFS Traversal :");
    while (!isEmpty(q)){
        TreeNode* current = dequeue(q);
        printf("%d ", current->data);
        if(current->left != NULL){
            enqueue(q,current->left);
        }
        if(current->right != NULL){
            enqueue(q,current->right);
        }
    }
    printf("\n");
}


// average of levels in BT->use BFS
void AvgOfLVLs(TreeNode* root){
    if(root==NULL){
        return;
    }
    Queue* q = createQueue(100);
    enqueue(q,root);
    int level = 0;

    while (!isEmpty(q)){
        int levelSize = q->rear - q->front;;
        double sum = 0;
        for (int i = 0; i < levelSize; i++){
            TreeNode* current = dequeue(q);
            sum += current->data;
            if(current->left != NULL){
            enqueue(q,current->left);
            }
            if(current->right != NULL){
                enqueue(q,current->right);
            }
        }
        
        double avg = sum/levelSize;
        printf("Avg of level %d: %.2f\n ", level,avg);
        level ++;
    }
}

int main() {
    TreeNode *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(18);

    printf("Simple Display:\n");
    display(root, 0);

    printf("\nPretty Display:\n");
    prettyDisplay(root, 0);

    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    BFS(root);
    AvgOfLVLs(root); //10.0,10.0,10.0
    return 0;
}
