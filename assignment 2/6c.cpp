#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int a[m][3], b[n][3], c[100][3];
    for (int i = 0; i < m; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    for (int i = 0; i < n; i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];
    int k = 1;
    c[0][0] = a[0][0];
    c[0][1] = b[0][1];
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[i][1] == b[j][0])
            {
                int r = a[i][0], col = b[j][1], val = a[i][2] * b[j][2], f = 0;
                for (int x = 1; x < k; x++)
                {
                    if (c[x][0] == r && c[x][1] == col)
                    {
                        c[x][2] += val;
                        f = 1;
                    }
                }
                if (!f)
                {
                    c[k][0] = r;
                    c[k][1] = col;
                    c[k][2] = val;
                    k++;
                }
            }
        }
    }
    c[0][2] = k - 1;
    for (int i = 0; i < k; i++)
        cout << c[i][0] << " " << c[i][1] << " " << c[i][2] << endl;
}
