#include <iostream>
using namespace std;
#include "14_1_linked_list._class.cpp"

Node *take()
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
        }
        cin >> data;
    }
    return head;
}

Node *del_node(int i, Node *head)
{
    int count = 1;
    Node *temp = head;
    if(i==0)
    {
        return head;
    }

    if (i == 1)
    {
        head = head->next;
        delete temp;
        return head;
    }

    while (temp != NULL && count < i - 1)
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
    print(head);
    cout << "Enter element " << endl;
    int i;

    cin >> i;

    Node *hd = del_node(i, head);
    print(hd);
    

    return 0;
}