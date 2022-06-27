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

    cout << endl;
    return head;
}

Node *insert(Node *head, int data, int i)
{

    Node *newnode = new Node(data);
    Node *temp = head;
    int count = 1;

    if(i==0)
    {
        return head;
    }

    if(i==1)
    {
        newnode->prev = NULL;
        newnode->next = head;
        head = newnode;
        return head;
    }

    while ( temp!=NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    if(temp!=NULL)
    {
        Node *a = temp->next;
        newnode->prev = temp;
        newnode->next = a;
        a->prev = newnode;
        temp->next = newnode;
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
    int data, i;
    cin >> data;
    cin >> i;
    Node *h2 = insert(head, data, i);
    print(h2);

    return 0;
}