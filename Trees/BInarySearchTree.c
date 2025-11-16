#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    int height;
}TreeNode;


TreeNode* createNode(int value){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;
    return newNode;
}

int height(TreeNode* node){
    if(node == NULL){
        return -1; // height of null tree = -1
    }
    return node->height;
}

void prettyDisplay(TreeNode *node, int level) {
    if (node == NULL) return;
    prettyDisplay(node->right, level + 1);
    if (level != 0) {
        for (int i = 0; i < level - 1; i++) printf("|\t\t");
        printf("|------->%d\n", node->value);
    } else {
        printf("%d\n", node->value);
    }
    prettyDisplay(node->left, level + 1);
}


// Insertion in BST
TreeNode* insert(TreeNode* root, int value){
    if(root == NULL){
        return createNode(value);
    }
    if(value < root->value){
        root->left = insert(root->left, value);
    }else if(value > root->value){
        root->right = insert(root->right, value);
    }else{
        return root;
    }

    // update heigt
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    root->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    return root;
}

// inorder traversal -> gives sorted order
void inOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ", root->value);
    inOrder(root->right);
}


// checking the BST is balanced or not
int isBalanced(TreeNode* root) {
    if (root == NULL)
        return 1; 
    int leftH = height(root->left);
    int rightH = height(root->right);
    int diff = leftH - rightH;
    if (diff < 0) diff = -diff; 
    if (diff > 1)
        return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    TreeNode* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);
    // root = insert(root,233);
    // root = insert(root,245);

    printf("Inorder traversal of BST: ");
    inOrder(root);
    printf("\n");

    printf("Height of root node: %d\n", root->height);
    printf("balanced or not 1->balanced/0->not: %d\n", isBalanced(root));

    prettyDisplay(root,0);
    return 0;
}