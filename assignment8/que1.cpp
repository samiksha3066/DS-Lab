#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Recursive Pre-order Traversal
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";  
    preorder(root->left);      
    preorder(root->right);
}   

// Recursive In-order Traversal
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);        
    cout << root->data << " ";  
    inorder(root->right);       
}

// Recursive Post-order Traversal
void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);      
    postorder(root->right);     
    cout << root->data << " ";  
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "Pre-order Traversal: ";
    preorder(root);

    cout << "\nIn-order Traversal: ";
    inorder(root);

    cout << "\nPost-order Traversal: ";
    postorder(root);

    return 0;
}

