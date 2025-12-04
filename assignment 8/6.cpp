#include <iostream>
using namespace std;

class MaxPQ {
private:
    int heap[100];   // fixed-size array
    int n;           // number of elements in heap

    void swapValues(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Move element up (used after insertion)
    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] < heap[i]) {
                swapValues(heap[parent], heap[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    // Move element down (used after deletion)
    void siftDown(int i) {
        while (true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int largest = i;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != i) {
                swapValues(heap[i], heap[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

public:
    MaxPQ() { n = 0; }

    bool empty() { return n == 0; }
    int size() { return n; }

    int top() {
        if (n == 0) throw runtime_error("Priority Queue Empty!");
        return heap[0];
    }

    void push(int x) {
        heap[n] = x;        // insert at end
        siftUp(n);          // fix heap
        n++;
    }

    int pop() {
        if (n == 0) throw runtime_error("Priority Queue Empty!");
        int root = heap[0];
        heap[0] = heap[n-1]; // move last to root
        n--;                 // shrink size
        siftDown(0);         // fix heap
        return root;
    }
};

int main() {
    MaxPQ pq;

    cout << "Inserting: 10, 40, 5, 20\n";
    pq.push(10);
    pq.push(40);
    pq.push(5);
    pq.push(20);

    cout << "Top = " << pq.top() << "\n"; // 40

    cout << "Pop = " << pq.pop() << "\n"; // removes 40
    cout << "Top = " << pq.top() << "\n"; // should be 20

    cout << "Push 100\n";
    pq.push(100);
    cout << "Top = " << pq.top() << "\n"; // 100

    cout << "Extract all: ";
    while (!pq.empty()) {
        cout << pq.pop() << " ";
    }

    return 0;
}
