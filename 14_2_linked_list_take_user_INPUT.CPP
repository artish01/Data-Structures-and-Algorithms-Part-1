#include <iostream>
using namespace std;
#include "14.1_linked_list._class.cpp"

Node *take()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newnode = new Node(data); // new node created in stack
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode ;
        }


            //Node *temp = head;

        //     while (temp->next != NULL)
        //     {
        //         temp = temp->next;
        //     }
        //     temp->next = newnode; // remember newnode is dynamically created object and conatin address of current object
        // }
        cin >> data;
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
    print(head);

    return 0;
}