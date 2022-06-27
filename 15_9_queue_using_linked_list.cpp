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
class Queue
{
    int size;
    Node<T> *head;
    Node<T> *tail;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getsize()
    {
        return size;
    }

    bool isempty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        Node<T> *newnode = new Node<T>(element);  // while creaating object the T is replaced by int
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
        size++;
    }
    T front()
    {
        if (isempty())
        {
            return 0;
        }
        return head->data;
    }

    T dequeue()
    {
        if (isempty())
        {
            return 0;
        }
        T d = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return d;
    }
};

int main()
{
    Queue<int> q1;
    q1.enqueue(21);
    q1.enqueue(41);
    q1.enqueue(1);
    cout << q1.front() << endl;
    cout << q1.getsize() << endl;
    q1.enqueue(91);
    q1.enqueue(111);
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout << q1.front() << endl;
 

    return 0;
}