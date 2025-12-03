#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}
// Recursive Search
Node* searchRec(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchRec(root->left, key);
    else
        return searchRec(root->right, key);
}
Node* searchNonRec(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}
Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;

    while (root->right != nullptr)
        root = root->right;

    return root;
}
Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;

    while (root->left != nullptr)
        root = root->left;

    return root;
}
Node* inorderSuccessor(Node* root, int key) {
    Node* current = searchNonRec(root, key);
    if (current == nullptr) return nullptr;
    if (current->right != nullptr)
        return findMin(current->right);
    Node* successor = nullptr;
    Node* ancestor = root;

    while (ancestor != current) {
        if (current->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}


Node* inorderPredecessor(Node* root, int key) {
    Node* current = searchNonRec(root, key);
    if (current == nullptr) return nullptr;
    if (current->left != nullptr)
        return findMax(current->left);
    Node* predecessor = nullptr;
    Node* ancestor = root;

    while (ancestor != current) {
        if (current->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        }
        else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main() {
    Node* root = nullptr;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    for (int key : keys)
        root = insert(root, key);

    cout << "In-order Traversal: ";
    inorder(root);
    cout <<endl;
    int item = 40;
    cout << "\nSearching for " << item << "...\n";
    cout << "Recursive Search: " 
         << (searchRec(root, item) ? "Found" : "Not Found") << endl;

    cout << "Non-recursive Search: " 
         << (searchNonRec(root, item) ? "Found" : "Not Found") << endl;

    // Max & Min
    cout << "\nMinimum element: " << findMin(root)->data << endl;
    cout << "Maximum element: " << findMax(root)->data << endl;

    // Successor
    Node* succ = inorderSuccessor(root, 40);
    if (succ) cout << "\nIn-order Successor of 40: " << succ->data << endl;
    else cout << "\nNo In-order Successor exists.\n";

    // Predecessor
    Node* pred = inorderPredecessor(root, 40);
    if (pred) cout << "In-order Predecessor of 40: " << pred->data << endl;
    else cout << "No In-order Predecessor exists.\n";

    return 0;
}
