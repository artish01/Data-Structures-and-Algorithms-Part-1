#include "iostream"
using namespace std;

class QueueUsingArrays
{
    int *data;    // data s dynamically created array
    int nextindex;
    int firstindex;
    int size;
    int capacity;

public:
    QueueUsingArrays(int s)
    {
        data = new int[s];  // dynamic declaration of arrays
        nextindex = 0;
        capacity = s;
        firstindex = -1;
        size = 0;
        
    }
      
    bool isempty()
    {
        return size == 0;
    }

    int getsize()
    {
        return size;
    }

    void enqueue(int d)
    {
        if (size == capacity)   // if this condition does not met it means their is still empty indexes
        {
            cout << "Queue Full";
        }

        data[nextindex] = d;
        nextindex = (nextindex + 1) % capacity;
        if (firstindex == -1)
        {
            firstindex = 0; 
        }
        size++;
    }

    int front()
    {
        if (isempty())
        {
            cout << "Queue is empty";
            return 0;
        }
        return data[firstindex];
    }

    int dequeue()
    {
        if (isempty())
        {
            cout << "Queue is empty";
            return 0;
        }
        int store = data[firstindex];
        firstindex = (firstindex+1)%capacity;
        size--;

        if(size==0)
        {
            firstindex =-1;
            nextindex =0;
        }
        return store;


        
    }
};

int main()
{
    QueueUsingArrays q1(5);

    q1.enqueue(12);
    q1.enqueue(2);
    q1.enqueue(21);
    q1.enqueue(13);
    cout<<q1.front()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    q1.enqueue(100);
    q1.enqueue(32);
    q1.enqueue(1);
    cout<<q1.front();

        return 0;
}