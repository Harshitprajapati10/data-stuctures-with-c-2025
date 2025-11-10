#include <stdio.h>
#include <stdlib.h>

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

// 1) WAF to find total no. of leaf nodes 
int getTotalleafNodes(TreeNode* root){
    if(root != NULL){
        if(root->left == NULL && root->right == NULL){
            return 1;
        }else{
            return getTotalleafNodes(root->left) + getTotalleafNodes(root->right);
        }
    }
    return 0;
}

//2) WAF to count no. of internal nodes
int getInternalNodes(TreeNode* root){
    if(root != NULL){
        if(root->left == NULL && root->right == NULL){
            return 0;
        }else{
            return 1 + getInternalNodes(root->left) + getInternalNodes(root->right);
        }
    }
    return 0;
}

//3) WAF to count total no. of nodes
int getTotalNodes(TreeNode* root){
    if(root != NULL){
        if(root->left == NULL && root->right == NULL){
            return 1;
        }else{
            return 1 + getTotalNodes(root->left) + getTotalNodes(root->right);
        }
    }
    return 0;
}


// 4) number of null links in internal nodes//2
int getNullLinksinInternalNodes(TreeNode* root){
    if(root != NULL){
        if(root->left == NULL && root->right == NULL){
            return 0;
        }else{
            return getNullLinksinInternalNodes(root->left) + getNullLinksinInternalNodes(root->right);
        }
    }
    return 1;
}

// 5) total number of null links in binary tree
int getTotalNullLinks(TreeNode* root){
    if(root!=NULL){
        return getTotalNullLinks(root->left) + getTotalNullLinks(root->right);
    }
    return 1;
}

//6)WAF to calculate height of the binary tree
int heightBT(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = heightBT(root->left);
    int rightHeight = heightBT(root->right);
    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }else{
        return rightHeight + 1;
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
    root->left->left->left = createNode(34);
    root->left->right->right = createNode(4);
    /*
        10
       / \
      5   15
     / \ / \
    3  7 12  18
    /   \
    34   4

    */

    // printf("\nPretty Display:\n");
    // prettyDisplay(root, 0);


    printf("%d \n",getTotalleafNodes(root));//4
    printf("%d \n",getInternalNodes(root));//5
    printf("%d \n",getTotalNodes(root));//9
    printf("%d \n",getNullLinksinInternalNodes(root));//2
    printf("%d \n",getTotalNullLinks(root));//10
    printf("%d \n",heightBT(root));//3
    return 0;
}
