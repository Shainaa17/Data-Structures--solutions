#include <iostream>
using namespace std;

int main()
{
    char str[100];
    cin.getline(str, 100);
    int freq[256] = {0};
    char q[100];
    int front = 0, rear = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            continue;
        freq[str[i]]++;
        q[rear++] = str[i];

        while (front < rear && freq[q[front]] > 1)
            front++;

        if (front < rear)
            cout << q[front] << " ";
        else
            cout << "-1 ";
    }
    cout << endl;
    return 0;
}
