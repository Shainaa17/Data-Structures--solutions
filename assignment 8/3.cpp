#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left, *right;
};
Node* createNode(int x){
    Node *t=new Node;
    t->data=x;
    t->left=t->right=NULL;
    return t;
}
Node *insert(Node* root,int key){
    if(!root) return createNode(key);
    if(key<root->data) root->left=insert(root->left,key);
    else if(key>root->data) root->right=insert(root->right,key);
    return NULL;
}
Node *deleteNode(Node *root,int key){
    if(!root) return root;
    if(key<root->data) root->left=deleteNode(root->left,key);
    else if(key>root->data) root->right=deleteNode(root->right,key);
    else{
        if(!root->left){
            Node *t=root->right;
            delete root;
            return t;
        }
        else if(!root->right){
            Node *t=root->left;
            delete root;
            return t;
        }
        Node *t=root->right;
        while(t->left) t=t->left;

        root->data=t->data;
        root->right=deleteNode(root->right,t->data);
    }
    return root;
}
int maxDepth(Node *root){
    if(!root) return 0;
    return 1+max(maxDepth(root->left),maxDepth(root->right));
}
int minDepth(Node *root){
    if(!root) return 0;
    if(!root->left) return 1+minDepth(root->right);
    if(!root->right) return 1+min(minDepth(root->left),minDepth(root->right));
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr) root = insert(root, x);

    cout << "Inorder Before Delete: ";
    inorder(root);

    root = deleteNode(root, 40);

    cout << "\nInorder After Delete: ";
    inorder(root);

    cout << "\nMax Depth = " << maxDepth(root);
    cout << "\nMin Depth = " << minDepth(root);

    return 0;
}