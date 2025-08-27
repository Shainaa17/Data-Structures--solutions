#include <iostream>
using namespace std;
class Stack {
    int arr[100];
    int top;
    public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1; 
    }
    bool isFull() {
        return top == 100 - 1;
    }
    void push(int x) {
        if (isFull()) { 
            cout << "Overflow"<<endl; 
            return;
        }
        arr[++top] = x;
    }
    void pop() {
        if (isEmpty()) { 
            cout << "Underflow"<<endl; 
            return; 
        }
        cout << "Popped: " << arr[top--] << endl;
    }
    void peek() {
        if (isEmpty()) cout << "Empty"<<endl;
        else cout << "Top: " << arr[top] << endl;
    }
    void display() {
        if (isEmpty()) { cout << "Empty\n"; return; }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};
int main() {
    Stack s;
    int ch, val;
    do {
        cout << "1.Push 2.Pop 3.Peek 4.Display 5.Exit"<<endl;
        cin >> ch;
        switch(ch) {
            case 1: cout << "Enter value: "; cin >> val; s.push(val); break;
            case 2: s.pop(); break;
            case 3: s.peek(); break;
            case 4: s.display(); break;
            default: cout<<"Enter a valid choice"<<endl; break;
        }
    } while(ch != 5);
    return 0;
}
