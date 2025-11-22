// 2. Write a program to count the number of occurrences of a given key in a singly linked
// list and then delete all the occurrences.
// Input: Linked List : 1->2->1->2->1->3->1 , key: 1
// Output: Count: 4 , Updated Linked List: 2->2->3.


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

    void push_back(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void result(int val) {
        int count = 0;
        while (head != NULL && head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            count++;
        }
        Node* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->data == val) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                if (toDelete == tail) {
                    tail = temp;
                }
                delete toDelete;
                count++;
            } else {
                temp = temp->next;
            }
        }
        cout << "Count: " << count << endl;
    }

    void print() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(1);
    l.push_back(2);
    l.push_back(1);
    l.push_back(3);
    l.push_back(1);

    cout << "Original List: ";
    l.print();

    int key = 1;
    l.result(key);

    cout << "Updated List: ";
    l.print();

    return 0;
}
