#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char s[100];
    cout << "Enter string: ";
    cin >> s;
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++)
    {
        char t = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = t;
    }
    cout << "Reversed string = " << s;
}
