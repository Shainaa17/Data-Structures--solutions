#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements in sorted order:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> key;
    int pos = binarySearch(arr, n, key);
    if (pos == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at position " << pos + 1 << endl;
}
