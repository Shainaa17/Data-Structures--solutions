#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    char s[n][100], t[100];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(s[j], s[j + 1]) > 0)
            {
                strcpy(t, s[j]);
                strcpy(s[j], s[j + 1]);
                strcpy(s[j + 1], t);
            }
        }
    }
    cout << "Sorted strings:" << endl;
    for (int i = 0; i < n; i++)
        cout << s[i] << endl;
}
