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

    ~Node(){
        delete next;
        delete prev;
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

            newnode->prev = temp;
            temp->next = newnode;
            temp = newnode;
        }
        cin >> data;
    }
    return head;
}

Node *reverse(Node *head)
{
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->prev = next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head= prev;
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
    cout<<endl;
}

int main()
{
    Node *head = take();
    Node *h2 = reverse(head);
    print(head);
    print(h2);

    return 0;
}