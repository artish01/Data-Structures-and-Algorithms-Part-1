#include "iostream"
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>

class stack
{
public:
    Node<T> *head;  //To store address of head 
    T size = 0;

    stack()
    {
        head = NULL;
    }
    bool isempty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    T top() 
    {
        if(isempty())
        {
            return 0;
        }
        return head->data;
    }

    void push(T data)
    {
        Node<T> *newnode = new Node<T>(data);
        if (head == NULL)
        {
            head = newnode;
            size++;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            size++;
        }
    }

    T pop()
    {
        if (isempty())
        {
            return 0;
        }
        Node<T> *temp = head;
        T store = temp->data;
        head = head->next;
        delete temp;
        size--;
        return store;
    }

    int tsize()
    {
        return size;
    }
};

int main()
{
    stack<int> s1;
    s1.push(101);
    s1.push(91);
    s1.push(121);
    s1.push(86);
    s1.push(95 );
    cout << s1.top() << endl;
    cout << s1.tsize() << endl;
    cout << s1.pop() << endl;
    cout << s1.tsize() << endl;
    cout << s1.isempty() << endl;

    return 0;
}