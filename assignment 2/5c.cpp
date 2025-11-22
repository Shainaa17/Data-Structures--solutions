#include <iostream>
using namespace std;

int getIndexLower(int i, int j)
{
    return i * (i + 1) / 2 + j;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int *L = new int[size];

    cout << "Enter lower triangular matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (i >= j)
                L[getIndexLower(i, j)] = x;
        }
    }

    cout << "\nStored 1D array:\n";
    for (int i = 0; i < size; i++)
        cout << L[i] << " ";
}
