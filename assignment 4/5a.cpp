#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    void reset() { // reinitialize after swap
        front = 0;
        rear = -1;
    }
};

class Stack {
    Queue *q1, *q2;
    int n;

public:
    Stack(int cap) {
        q1 = new Queue(cap);
        q2 = new Queue(cap);
        n = cap;
    }

    void push(int x) {
        if (q1->isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        // Step 1: enqueue into q2
        q2->enqueue(x);

        // Step 2: move all elements from q1 to q2
        while (!q1->isEmpty()) {
            q2->enqueue(q1->dequeue());
        }

        // Step 3: swap q1 and q2
        Queue *temp = q1;
        q1 = q2;
        q2 = temp;

        // reset q2 for next use
        q2->reset();
    }

    void pop() {
        if (q1->isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q1->dequeue();
    }

    int top() {
        if (q1->isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return q1->getFront();
    }

    bool isEmpty() {
        return q1->isEmpty();
    }
};

int main() {
    Stack s(10);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;  // 30
    s.pop();

    cout << "Top: " << s.top() << endl;  // 20
    s.pop();

    cout << "Top: " << s.top() << endl;  // 10
    s.pop();

    s.pop(); // Underflow

    return 0;
}
