#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int a[t][3], b[t][3];
    for (int i = 0; i < t; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    int k = 0;
    for (int c = 0; c < a[0][1]; c++)
    {
        for (int i = 0; i < t; i++)
        {
            if (a[i][1] == c)
            {
                b[k][0] = a[i][1];
                b[k][1] = a[i][0];
                b[k][2] = a[i][2];
                k++;
            }
        }
    }
    for (int i = 0; i < t; i++)
        cout << b[i][0] << " " << b[i][1] << " " << b[i][2] << endl;
}
