#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX];
int n = 0; 

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    int pos, value;
    cout << "Enter position to insert : ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> value;
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    n++;
}

void removeElement() {
    int pos;
    cout << "Enter position to delete : ";
    cin >> pos;
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void linearSearch() {
    int ele;
    cout << "Enter value to search: ";
    cin >> ele;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == ele) {
            cout << "Element found at position " << i + 1 << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Element not found"<<endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1. CREATE"<<endl;
        cout << "2. DISPLAY"<<endl;
        cout << "3. INSERT"<<endl;
        cout << "4. DELETE"<<endl;
        cout << "5. LINEAR SEARCH"<<endl;
        cout << "6. EXIT"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: removeElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting"<<endl; return 0;
        }
    }
}
