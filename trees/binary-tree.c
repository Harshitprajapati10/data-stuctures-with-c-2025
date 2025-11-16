

// 1,2,3,4 solved


#include <stdio.h>

typedef struct TreeNode{
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createNode(int value){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if(!newNode){
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorderTraversal(TreeNode* root){
    if(root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->value);
    inorderTraversal(root->right);
}



void preOrderTraversal(TreeNode* root){
    if(root == NULL) return;
    printf("%d ", root->value);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


void postOrderTraversal(TreeNode* root){
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->value);
}


void insertNode(TreeNode** root, int value){
    if(*root == NULL){
        *root = createNode(value);
        return;
    }
    if(value < (*root)->value){
        insertNode(&((*root)->left), value);
    } else {
        insertNode(&((*root)->right), value);
    }
}

void countNodes(TreeNode* root, int* count){
    if(root == NULL) return;
    (*count)++;
    countNodes(root->left, count);
    countNodes(root->right, count);
}

void deleteNode(TreeNode* root, TreeNode* nodeToDelete){
    if(root == NULL || nodeToDelete == NULL) return;
    if(root->left == nodeToDelete){
        free(nodeToDelete);
        root->left = NULL;
    } else if(root->right == nodeToDelete){
        free(nodeToDelete);
        root->right = NULL;
    } else {
        deleteNode(root->left, nodeToDelete);
        deleteNode(root->right, nodeToDelete);
    }
}

// left most node is the smallest node in Bst
TreeNode* getSmallestNode(TreeNode* root){
    if(root == NULL) return NULL;
    TreeNode* current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

// right most node is the largest node in Bst
TreeNode* getLargestNode(TreeNode* root){
    if(root == NULL) return NULL;
    TreeNode* current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return current;
}
