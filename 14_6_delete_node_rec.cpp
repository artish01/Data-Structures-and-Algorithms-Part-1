#include  <iostream>
using  namespace std;
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

Node *rem_rec(Node *head,int i)
{
    if(head ==NULL)
    {
        return head;
    }
    if(i==0)
    {
        Node *temp = head;
        head = temp->next;
        delete(temp);
        return head;
    }
    Node *a = rem_rec(head->next,i-1);
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
    int i;
    cin>>i;
    cout<<endl;
    head= rem_rec(head,i);
    print(head);
   


    


    return 0;


}