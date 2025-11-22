// Write a program to reverse a linked list.
// Input: 1->2->3->4->NULL
// Output: 4->3->2->1->NULL

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node *head;
    Node *tail;
public:
    List() {
        head = tail = NULL;
    }

    void insert(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse() {
        Node *prev = NULL, *temp = head, *next = NULL;
        while (temp != NULL) {
            next = temp->next;    
            temp->next = prev;    
            prev = temp;          
            temp = next;          
        }
        head = prev;  
    }
};

int main() {
    List l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);

    cout << "Original List: ";
    l.print();

    l.reverse();

    cout << "Reversed List: ";
    l.print();

    return 0;
}
