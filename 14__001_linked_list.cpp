#include  <iostream>
using  namespace std;
#include "14_1_linked_list._class.cpp"

// class Node
// {
//     public:
//         int data;
//         Node *next;
//         Node(int data)
//         {
//             this->data = data;
//             next = NULL;

//         }
// };

void print(Node *head)
{
    Node *tmp = head;
    while(tmp != NULL)
    {
        // cout<<(*tmp).data<<" ";
        cout<<tmp->data<<" ";
        tmp = tmp->next;

    }
}

int main()
{
    //statically
    // Node N1(3);
    // Node *head = &N1;  // it will storre adress of head as it is required
    // Node N2(4);
    // Node N3(5);
    // N1.next= &N2;

    // N2.next= &N3;
    // rint(head);
    
    // dynamically
    Node *N1 = new Node(12);
    Node *head = N1;    // it will storre adress of n1 as it is required
    Node *N2 = new Node(2);
    Node *N3 = new Node(5);

    
    N1->next = N2;
    N2->next = N3;
    print(head);

    


    return 0;


}