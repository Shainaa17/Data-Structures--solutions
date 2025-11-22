#include <iostream>
using namespace std;
#define MAX 100
int arr[MAX];
int n = 0;
void createArr() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}
void display() {
    if (n == 0) {
        cout << "Array is empty" << endl;
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertElement() {
    int pos, val;
    cout << "Enter position to insert: ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;
}
void deleteElement() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    if (pos < 1 || pos > n) {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}
void linearSearch() {
    int x, f = 0;
    cout << "Enter value to search: ";
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << "Element found at position " << i + 1 << endl;
            f = 1;
            break;
        }
    }
    if (!f) {
        cout << "Element not found" << endl;
    }
}
int main() {
    int ch;
    while (1) {
        cout << "\n1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1: createArr(); break;
            case 2: display(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: 
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
