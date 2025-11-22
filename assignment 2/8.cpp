#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        int f = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                f = 1;
                break;
            }
        }
        if (!f)
            c++;
    }
    cout << c;
}
