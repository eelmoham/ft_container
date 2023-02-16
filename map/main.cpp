#include <iostream>
using namespace std;

// Define the structure of a binary tree node
struct Node {
    int data;
    Node *left;
    Node *right;
};

// Function to create a new binary tree node
Node* newNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform an in-order traversal of a binary tree
void inOrderTraversal(Node *node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}

int main() {
    // Create a binary tree
    Node *root = newNode(0);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    // Perform an in-order traversal of the binary tree
    inOrderTraversal(root);

    return 0;
}
