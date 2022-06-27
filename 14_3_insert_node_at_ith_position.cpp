#include <iostream>
using namespace std;
#include "14_1_linked_list._class.cpp"

Node *get()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {

            tail->next = newnode;
            tail = newnode;
            // Node *temp = head
            // while(temp->next!= NULL)
            // {
            //     temp = temp->next;
            // }
            // temp->next = newnode;
        }
        cin >> data;
    }
    return head;
}

Node *insert_node(int data, Node *head, int i)
{

    Node *newnode = new Node(data);
    int count = 0; /// to reach the number  to which we have to replace

    Node *temp = head;
    if (head == NULL)
    {
        return head;
    }

    if (i == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }

    while (temp != NULL && count < i - 1) // we use null bcz if element position is greater then the size of ll then it willsimply exit
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)

    {
        // Node *a = temp->next;
        // temp->next = newnode;
        // newnode->next = a;
        newnode->next = temp->next;
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

    Node *head = get();
    cout << " enter element ";
    int data, i;
    cin >> data;
    cin >> i;

    Node *hd = insert_node(data, head, i);
    print(hd);

    return 0;
}