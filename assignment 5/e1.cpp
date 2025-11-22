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

class List {
public:
    Node* head;
    Node* tail;
    List() {
        head = tail = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Brute-force intersection based on matching data
Node* findIntersection(List l1, List l2) {
    Node* temp1 = l1.head;
    while (temp1) {
        Node* temp2 = l2.head;
        while (temp2) {
            if (temp1->data == temp2->data) {
                return temp1; // first common node based on data
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return NULL;
}

int main() {
    List l1, l2;

    // List 1
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(6);

    // List 2
    l2.push_back(4);
    l2.push_back(5);
    l2.push_back(3); // common data with list 1

    cout << "List 1: ";
    l1.print();
    cout << "List 2: ";
    l2.print();

    Node* inter = findIntersection(l1, l2);
    if (inter)
        cout << "Intersection at node with data: " << inter->data << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}
