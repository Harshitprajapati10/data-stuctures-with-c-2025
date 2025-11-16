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


// 1) calculate diameter of BT 

int main() {
    TreeNode *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->left->left->left = createNode(12);
    root->left->left->right = createNode(43);
    root->left->left->right->left = createNode(43);
    root->left->left->right->left->left = createNode(43);
    root->left->right->right = createNode(7);
    root->left->right->right->left = createNode(6);
    root->left->right->right->left->right = createNode(76);
    root->left->right->right->left->right = createNode(76);
   
    /*
                     10
                   /    \
                 5        15
               /   \      /
             3      7    12
           /  \      \
         12   43      7
              /       /
            43       6
           /           \
         43             76

         diameter = 9

    */

    printf("\nPretty Display:\n");
    prettyDisplay(root, 0);

    
}