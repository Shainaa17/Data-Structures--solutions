#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Circular {
    Node* head;
    Node* tail;
public:
    Circular() {
        head = tail = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void display() {
        if(head == NULL) {
            cout << "empty list\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);

        cout << head->data << endl;  // repeat head at the end
    }
};

int main() {
    Circular clist;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for(int i = 0; i < n; i++) {
        cin >> val;
        clist.insert(val);
    }

    cout << "Circular Linked List with head repeated at end:\n";
    clist.display();

    return 0;
}
