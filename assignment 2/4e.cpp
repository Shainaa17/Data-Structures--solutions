#include <iostream>
using namespace std;
int main()
{
    char c;
    cout << "Enter character: ";
    cin >> c;
    if (c >= 'A' && c <= 'Z')
        c = c + 32;
    cout << "Lowercase = " << c;
}
