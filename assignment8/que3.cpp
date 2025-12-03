#include <iostream>
#include <algorithm>
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
    else
        cout << "Duplicate value ignored: " << key << endl;

    return root;
}

Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children → get inorder successor
        Node* temp = findMin(root->right);
        root->data = temp->data;   // Copy successor value
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
int minDepth(Node* root) {
    if (root == nullptr)
        return 0;

    // If one subtree is missing
    if (root->left == nullptr && root->right != nullptr)
        return 1 + minDepth(root->right);

    if (root->right == nullptr && root->left != nullptr)
        return 1 + minDepth(root->left);

    // If both subtrees exist
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node* root = nullptr;

    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : elements)
        root = insert(root, x);

    cout << "In-order Traversal: ";
    inorder(root);
    cout << endl;

    // Deletion
    cout << "\nDeleting 20...\n";
    root = deleteNode(root, 20);
    cout << "In-order after deletion: ";
    inorder(root);
    cout << endl;

    cout << "\nMaximum Depth of BST: " << maxDepth(root) << endl;
    cout << "Minimum Depth of BST: " << minDepth(root) << endl;

    return 0;
}
