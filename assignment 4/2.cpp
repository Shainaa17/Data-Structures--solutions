#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int capacity;
public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == (rear + 1) % capacity);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = val;
        cout << val << " enqueued to the queue\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        int val = arr[front];
        if (front == rear) { // only one element
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        cout << val << " dequeued from the queue\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element is: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter size of circular queue: ";
    cin >> size;

    CircularQueue cq(size);
    int choice, val;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. IsEmpty\n6. IsFull\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                cq.enqueue(val);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.peek();
                break;
            case 4:
                cq.display();
                break;
            case 5:
                cout << (cq.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
                break;
            case 6:
                cout << (cq.isFull() ? "Queue is full\n" : "Queue is not full\n");
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
