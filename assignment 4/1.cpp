#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return rear < front;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        arr[++rear] = val;
        cout << val << " enqueued to the queue\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        int val = arr[front++];
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
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter size of the queue: ";
    cin >> size;

    Queue q(size);
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
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
                break;
            case 6:
                cout << (q.isFull() ? "Queue is full\n" : "Queue is not full\n");
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
