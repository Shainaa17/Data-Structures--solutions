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

bool isBSTUtil(Node* root, int minV, int maxV) {
    if (!root) return true;
    if (root->data <= minV || root->data >= maxV) return false;

    return isBSTUtil(root->left, minV, root->data) &&
           isBSTUtil(root->right, root->data, maxV);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -1000000000, 1000000000);
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(2);

    cout << "Tree is BST? "
         << (isBST(root) ? "YES" : "NO");

    return 0;
}
