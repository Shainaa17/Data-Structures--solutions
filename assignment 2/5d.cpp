#include <iostream>
using namespace std;

int getIndexUpper(int i, int j, int n)
{
    return i * n - (i * (i - 1)) / 2 + (j - i);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int *U = new int[size];

    cout << "Enter upper triangular matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (i <= j)
                U[getIndexUpper(i, j, n)] = x;
        }
    }

    cout << "\nStored 1D array:\n";
    for (int i = 0; i < size; i++)
        cout << U[i] << " ";
}
