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

    void middle() {
        Node *curr = head;
        int count = 0;
        while (curr != NULL) {
            curr = curr->next;
            count++;
        }

        Node *temp = head;
        if (count % 2 != 0) {  
            int mid = count / 2;
            int c = 0;
            while (temp != NULL) {
                if (c == mid) {
                    cout << "Middle: " << temp->data << endl;
                }
                c++;
                temp = temp->next;
            }
        } else {
            int mid1 = count / 2 - 1;
            int mid2 = count / 2;
            int c = 0;
            cout << "Middle elements: ";
            while (temp != NULL) {
                if (c == mid1 || c == mid2) {
                    cout << temp->data << " ";
                }
                c++;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    List l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);

    cout << "Linked List: ";
    l.print();

    l.middle();

    return 0;
}
