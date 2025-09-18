#include <iostream>
using namespace std;
class Stack {
    char arr[100];
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
        arr[++top] = x;
    }
    char pop() {
        return arr[top--];
    }
};

int main() {
    string str;
    cout << "Enter a string: ";
    cin>>str;
    Stack s;
    for (char c : str){
        s.push(c);
    }
    while (!s.isEmpty()){
        cout<<s.pop();
    }
    cout << endl;

    return 0;
}
