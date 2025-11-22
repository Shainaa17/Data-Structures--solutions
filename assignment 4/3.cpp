#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int size;
    int front, rear;

public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear) { // only one element
            front = rear = -1;
        } else {
            front++;
        }
        return val;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getSize() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Interleave first half with second half
    void interleave() {
        int n = getSize();
        if (n % 2 != 0) {
            cout << "Queue must have even number of elements\n";
            return;
        }

        int mid = n / 2;
        int *firstHalf = new int[mid];

        // Store first half in temp array
        for (int i = 0; i < mid; i++) {
            firstHalf[i] = dequeue();
        }

        // Now arr[front..rear] is second half
        int secondHalfStart = front;
        int newRear = -1;

        int *newArr = new int[size];

        // Interleave elements from both halves
        for (int i = 0; i < mid; i++) {
            newArr[++newRear] = firstHalf[i];   // from first half
            newArr[++newRear] = arr[secondHalfStart++]; // from second half
        }

        // Reset queue with interleaved result
        front = 0;
        rear = newRear;
        for (int i = 0; i <= rear; i++) {
            arr[i] = newArr[i];
        }

        delete[] firstHalf;
        delete[] newArr;
    }
};

int main() {
    Queue q(10);
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);

    cout << "Original Queue: ";
    q.display();

    q.interleave();

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}
