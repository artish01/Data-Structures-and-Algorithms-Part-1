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

        if (tail == 0)
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

int len(Node *tail)
{
    Node *temp = tail->next;

    int count = 1;

    while (temp->next != tail->next)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

Node *end(Node *tail, int i, Node *newnode)
{

    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode;
    return tail;
}

Node *insert(Node *tail, int i, int d)
{
    if(tail==NULL)
    {
         cout<<"false";
         return tail;
    }
    int l = len(tail);
 
    int count = 1;
    Node *temp = tail->next;
    Node *newnode = new Node(d);

    if (i <= (l + 1) && i >= 1)  // this clearly shows that this is non-index based;
    {

        if (i == 1)
        {
            // insert at beg..
            newnode->next = tail->next;
            tail->next = newnode;
            return tail;
        }
        else if (i == (l + 1))
        {
            cout << "i am in " << endl;
            Node *tl = end(tail, i, newnode);
            return tl;
        }

        else
        {
            while (count < i - 1)
            {
                temp = temp->next;
                count++;
            }
            
            Node *a = temp->next;
            newnode->next = a;
            temp->next = newnode;
        }
    }
    else{
        cout<<"invalid position";

        cout<<endl;
    }

    return tail;
}

int main()
{

    Node *tail = take();
    print(tail);
    cout << endl;
    int i, d;
    cin >> i;

    cin >> d;
    Node *h2 = insert(tail, i, d);
    print(h2);

    return 0;
}