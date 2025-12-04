#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int x) {
    Node* t = new Node;
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

Node* insert(Node* root, int key) {
    if (!root) return createNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        root = (key < root->data ? root->left : root->right);
    }
    return NULL;
}

int findMin(Node* root) {
    while (root->left) root = root->left;
    return root->data;
}

int findMax(Node* root) {
    while (root->right) root = root->right;
    return root->data;
}

Node* inorderSuccessor(Node* root, Node* x) {
    Node* succ = NULL;
    while (root) {
        if (x->data < root->data) {
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* x) {
    Node* pred = NULL;
    while (root) {
        if (x->data > root->data) {
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}

int main() {
    Node* root = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr) root = insert(root, x);

    cout << "Search 40 Rec: " 
         << (searchRec(root, 40) ? "Found" : "Not Found");

    cout << "\nSearch 90 Iter: " 
         << (searchIter(root, 90) ? "Found" : "Not Found");

    cout << "\nMin element = " << findMin(root);
    cout << "\nMax element = " << findMax(root);

    Node* x = searchRec(root, 60);
    cout << "\nSuccessor of 60 = " 
         << (inorderSuccessor(root, x) ? inorderSuccessor(root, x)->data : -1);

    cout << "\nPredecessor of 60 = "
         << (inorderPredecessor(root, x) ? inorderPredecessor(root, x)->data : -1);

    return 0;
}
