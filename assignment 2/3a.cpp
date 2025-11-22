#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int arr[n - 1], sum = 0;
    cout << "Enter " << n - 1 << " elements:" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int total = n * (n + 1) / 2;
    cout << "Missing number = " << total - sum;
}
