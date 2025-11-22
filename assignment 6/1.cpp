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

class Circular {
    Node *head;
    Node *tail;
public:
    Circular() {
        head = tail = NULL;
    }

    void insert(int val, int pos) {
        Node *newNode = new Node(val);
        if(pos == 0) {
            if(head == NULL) {
                head = tail = newNode;
                tail->next = head;
            } else {
                newNode->next = head;
                head = newNode;
                tail->next = head;
            }
            return;
        }

        Node *temp = head;
        for(int i = 0; i < pos-1; i++)
            temp = temp->next;

        if(temp == tail) {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void del(int pos) {
        if(head == NULL) return;

        if(pos == 0) {
            Node *temp = head;
            if(head == tail) {
                head = tail = NULL;
            } else {
                head = head->next;
                tail->next = head;
            }
            delete temp;
            return;
        }

        Node *curr = head;
        for(int i = 0; i < pos-1; i++)
            curr = curr->next;

        Node *toDelete = curr->next;
        if(toDelete == tail)
            tail = curr;

        curr->next = toDelete->next;
        delete toDelete;
    }

    void search(int val) {
        if(head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        do {
            if(temp->data == val) {
                cout << "Value found\n";
                return;
            }
            temp = temp->next;
        } while(temp != head);
        cout << "Value not found\n";
    }

    void display() {
        if(head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);
        cout << endl;
    }
};

int main() {
    Circular clist;
    int choice, val, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter position: ";
                cin >> pos;
                clist.insert(val, pos);
                break;
            case 2:
                cout << "Enter position to delete: ";
                cin >> pos;
                clist.del(pos);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                clist.search(val);
                break;
            case 4:
                clist.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 5);

    return 0;
}
