#include <iostream>
using namespace std;

// Function to sort array into negatives, zeros, and positives
void dutchNationalFlag(int a[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (a[mid] < 0) {           // Negative numbers
            swap(a[low], a[mid]);
            low++;
            mid++;
        } else if (a[mid] == 0) {   // Zeros
            mid++;
        } else {                     // Positive numbers
            swap(a[mid], a[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int a[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dutchNationalFlag(a, n);

    cout << "Array after segregation: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
