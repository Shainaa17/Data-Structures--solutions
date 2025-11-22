#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *prev;
    Node *next;
};

Node *createNode(char ch)
{
    Node *newNode = new Node;
    newNode->data = ch;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node **head, char ch)
{
    Node *newNode = createNode(ch);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

bool isPalindrome(Node *head)
{
    if (head == NULL)
        return true;
    Node *left = head;
    Node *right = head;
    while (right->next != NULL)
        right = right->next;

    while (left != right && left->prev != right)
    {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main()
{
    Node *head = NULL;
    string s;
    cout << "Enter characters: ";
    cin >> s;
    for (int i = 0; s[i] != '\0'; i++)
        insertEnd(&head, s[i]);

    if (isPalindrome(head))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}
