#include <stdio.h>
#include <stdlib.h>
// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Function to create a new tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);      // Traverse left subtree
    printf("%d ", node->data);         // Visit root
    inorderTraversal(node->right);     // Traverse right subtree
}
// Preorder Traversal (Root -> Left -> Right)
void preorderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);         // Visit root
    preorderTraversal(node->left);     // Traverse left subtree
    preorderTraversal(node->right);    // Traverse right subtree
}
// Postorder Traversal (Left -> Right -> Root)
void postorderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    postorderTraversal(node->left);    // Traverse left subtree
    postorderTraversal(node->right);   // Traverse right subtree
    printf("%d ", node->data);         // Visit root
}
// Function to free the memory allocated for the tree
void freeTree(struct Node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}
// Main function to demonstrate tree traversals
int main() {
    // Constructing a sample binary tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");
    // Free allocated memory
    freeTree(root);
//}Inorder Traversal: 4 2 5 1 3 
//Preorder Traversal: 1 2 4 5 3 
//Postorder Traversal: 4 5 2 3 1 