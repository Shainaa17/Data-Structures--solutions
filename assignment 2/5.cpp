#include <iostream>
#include <cctype>
using namespace std;
class Stack {
    int arr[100];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
};
int evaluatePostfix(string exp) {
    Stack s;
    for (char c : exp) {
        if (isdigit(c)) s.push(c - '0');
        else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch(c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}
int main() {
    cout<<"enter postfix expression"<<endl;
    string expr;
    cin>>expr;
    cout << "Result: " << evaluatePostfix(expr);
    return 0;
}
