#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

Node *take()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *temp = NULL;

    while (data != -1)
    {
        Node *newnode = new Node(data);

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        cin >> data;
    }
    return head;
}

Node *dlt(Node *head, int del)
{
    int count = 1;
    Node *temp = head;
    if (head == NULL)
    {
        return head;
    }

    if (del == 1)
    {
        head = temp->next;
        delete temp;
        return head;
    }
    while (temp != NULL && count < del - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        Node *a = temp->next;
        Node *b = a->next;
        temp->next = b;
        delete a;
    }
    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{

    Node *head = take();
    int del;
    cin >> del;
    Node *h2 = dlt(head, del);
    print(h2);
    return 0;
}