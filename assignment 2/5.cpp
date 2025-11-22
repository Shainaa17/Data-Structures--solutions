#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; i++)
        cin >> d[i];
    int i, j;
    cin >> i >> j;
    if (i == j)
        cout << d[i];
    else
        cout << 0;
}
