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
bool isBalanced(string expr) {
    Stack s;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '['){
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (s.isEmpty()) return false;
            char top = s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) return false;
        }
    }
    return s.isEmpty();
}
int main() {
    string str;
    cout<<"Enter expression";
    cin>>str;
    cout << (isBalanced(str) ? "Balanced" : "Not Balanced");
    return 0;
}
