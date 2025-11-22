#include <iostream>
using namespace std;

int getIndexSym(int i, int j)
{
    if (i < j)
        swap(i, j);
    return i * (i + 1) / 2 + j;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int *S = new int[size];

    cout << "Enter symmetric matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            S[getIndexSym(i, j)] = x;
        }
    }

    cout << "\nStored 1D array:\n";
    for (int i = 0; i < size; i++)
        cout << S[i] << " ";
}
