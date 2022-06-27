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
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next= newnode;
            tail= newnode;
            //                                             Node *temp = head;
            //                                             while (temp->next != NULL)
            //                                             {
            //                                                 temp = temp->next;
            //                                             }
            //                                              temp->next = newnode;
        }
        
        cin >> data;
    }
    return head;
}

Node *insert_rec(Node *head,int data,int i)
{
    if(head==NULL)
    {
        return head;
    }

    if(i==0)
    {
        Node *newnode = new Node(data);
        newnode->next = head;
        head = newnode;
        return head;


    }
    Node *a= insert_rec(head->next,data,i-1);
    head->next = a;
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = take();
    print(head);
    cout<<endl;
    int data,i;
    cin>>i>>data;
    cout<<endl;
    head= insert_rec(head,data,i);
    print(head);

    return 0;
}
