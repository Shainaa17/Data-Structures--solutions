#include <iostream>
using namespace std;

int getIndex(int i, int j, int n)
{
    if (i == j)
        return i;
    else if (i == j + 1)
        return n + j;
    else if (i + 1 == j)
        return 2 * n - 1 + i;
    return -1;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int size = 3 * n - 2;
    int *T = new int[size];

    cout << "Enter tri-diagonal matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            int idx = getIndex(i, j, n);
            if (idx != -1)
                T[idx] = x;
        }
    }

    cout << "\nStored 1D array:\n";
    for (int i = 0; i < size; i++)
        cout << T[i] << " ";
}
