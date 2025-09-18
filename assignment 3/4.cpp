#include <iostream>
using namespace std;
class Stack {
    char arr[100];
    int top;
    public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    void push(char c) { arr[++top] = c; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
};
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}
string infixToPostfix(string expr) {
    Stack s;
    string result;
    for (char c : expr) {
        if (isalnum(c)) result += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '('){
                result += s.pop();
            }
            s.pop(); 
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)){
                result += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) result += s.pop();
    return result;
}
int main() {
    cout<<"Enter expression";
    string expr;
    cin>>expr;
    cout << "Postfix: " << infixToPostfix(expr);
    return 0;
}
