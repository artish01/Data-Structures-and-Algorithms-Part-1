#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *take()
{
    int data;
    cin >> data;

    Node *tail = NULL;

    while (data != -1)
    {
        Node *newnode = new Node(data);

        if (tail == NULL)
        {

            tail = newnode;
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = tail->next;
        }

        cin >> data;
    }

    return tail;
}
int len(Node *tail)
{
    Node *temp = tail->next;
    int count = 1;
    while (temp->next != tail->next)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

Node *end(Node *tail, int n)
{
    // Node *curr = tail->next;
    // Node *prev = NULL;

    // while (curr->next != tail->next)
    // {
    //     prev = curr;
    //     curr = curr->next;
    // }

    // prev->next = tail->next;
    // delete (curr);
    // tail = prev;

    // return tail;

    // Method 2 

    Node *temp = tail->next;
    int count = 1;

    while(count<n-2)
    {
        temp = temp->next;
        count++;
    }
    Node *a = temp->next;
    Node *b = a->next;
    a->next = tail->next;
    tail = a;
    delete(b);
    
    return tail;
}

void mid(Node *tail, int n)
{
    int count = 1;
    Node *temp = tail->next;

    while (count < n - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *a = temp->next;
    Node *b = a->next;
    temp->next = b;
    delete (a);
}

Node *deleted(Node *tail, int n)
{
    Node *temp = tail->next;
    int l = len(tail);

    if (temp == NULL)
    {
        cout << "invalid";
        return tail;
    }
    if (n >= 1 && n <= l)
    {
        if (temp->next == temp)
        {

           
            tail = NULL;
            delete (tail);
        }

        else if (n == 1)
        {

            tail->next = temp->next;

            delete (temp);
            return tail;
        }
        else if (n == l)
        {

            Node *t1 = end(tail, n);
            return t1;
        }
        else
        {
            mid(tail, n);
            return tail;
        }
    }
    else
    {
        cout << " position invalid ";
    }

    return tail;
}

void print(Node *tail)
{
    Node *temp = tail->next;
    while (temp->next != tail->next)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
}

int main()
{
    Node *head = take();
    int n;
    cin >> n;
    Node *h2 = deleted(head, n);
    print(h2);

    return 0;
}