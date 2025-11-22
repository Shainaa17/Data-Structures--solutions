#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int a[m][3], b[n][3], c[m + n][3];
    for (int i = 0; i < m; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    for (int i = 0; i < n; i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];
    int i = 1, j = 1, k = 1;
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    while (i < m && j < n)
    {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1]))
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k++][2] = a[i++][2];
        }
        else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1]))
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k++][2] = b[j++][2];
        }
        else
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k++][2] = a[i][2] + b[j][2];
            i++;
            j++;
        }
    }
    while (i < m)
    {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k++][2] = a[i++][2];
    }
    while (j < n)
    {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k++][2] = b[j++][2];
    }
    c[0][2] = k - 1;
    for (int x = 0; x < k; x++)
        cout << c[x][0] << " " << c[x][1] << " " << c[x][2] << endl;
}
