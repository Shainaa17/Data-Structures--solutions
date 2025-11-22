#include <iostream>
using namespace std;

// ---------------- Stack Class ----------------
class Stack {
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};

// ---------------- Queue using 2 Stacks ----------------
class QueueUsingStacks {
    Stack s1, s2; // two stacks
    int capacity;

public:
    QueueUsingStacks(int size) : s1(size), s2(size) {
        capacity = size;
    }

    void enqueue(int x) {
        if (s1.isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        s1.push(x);
        cout << x << " enqueued\n";
    }

    int dequeue() {
        if (s1.isEmpty() && s2.isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }

        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }

        int val = s2.pop();
        cout << val << " dequeued\n";
        return val;
    }

    bool isEmpty() {
        return s1.isEmpty() && s2.isEmpty();
    }
};

// ---------------- Main ----------------
int main() {
    QueueUsingStacks q(10);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();
    q.dequeue();

    q.enqueue(40);

    q.dequeue();
    q.dequeue();

    return 0;
}
