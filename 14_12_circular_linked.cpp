#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
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

        if (tail == 0)
        {
            
            tail = newnode;
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next =  newnode;
            // tail = tail->next;
            tail = newnode;
        }
       
        cin >> data;
    }
    return tail;
}

void print(Node *tail)
{
    Node *temp = tail->next;
    while (temp->next != tail->next)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data;
}

int main()
{
    Node *head = take();
    print(head);

    return 0;
}