#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class List{
    public:
    Node *head;
    Node *tail;
    public:
    List(){
        head=tail=NULL;
    }
    void push_front(int val){
        Node *newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }else{
            newNode -> next = head;
            head=newNode;
        }
    }
    void push_back(int val){
        Node *newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void insert(int val,int pos){
        Node *newNode=new Node(val);
        Node *temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        if(pos<0){
            cout<<"enter a valid value";
        }
        if(pos==0){
            push_front(val);
        }
    }
    void pop_front(){
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void pop_back(){
        Node *temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }
    void del(int pos){
        Node *temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        Node* toDelete = temp->next;
        temp->next=temp->next->next;
        delete toDelete;

        if(pos<0){
            cout<<"enter valid value";
        }
    }
    void search(int val){
        Node *temp=head;
        while(temp!=NULL){
            if(temp->data==val){
                cout<<"found";
                return;
            }
            temp=temp->next;
        }
        cout<<"not found";
    }
    void print(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main() {
    List l;
    int ch, val, pos, key;

    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete at position\n";
        cout << "7. Search for a node\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                l.push_front(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                l.push_back(val);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                l.insert(val, pos);
                break;
            case 4:
                l.pop_front();
                break;
            case 5:
                l.pop_back();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                l.del(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> key;
                l.search(key);
                break;
            case 8:
                l.print();
                cout << endl;
                break;
            case 9:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
