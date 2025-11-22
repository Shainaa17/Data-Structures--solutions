#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int start = 0, end = n - 1;

    while(start < end) {
        int min = start, max = start;
        for(int i = start; i <= end; i++) {
            if(arr[i] < arr[min]) min = i;
            if(arr[i] > arr[max]) max = i;
        }
        swap(arr[start], arr[min]);
        if(max == start) max = min;
        swap(arr[end], arr[max]);

        start++;
        end--;
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
