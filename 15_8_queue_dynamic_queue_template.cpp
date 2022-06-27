#include "iostream"
using namespace std;

template <typename T>
class QueUsingArrays
{
    T *data;  
    int firstindex;
    int nextindex;
    int size;
    int cap;

public:
    QueUsingArrays(int s)
    {
        data = new T[s];
        firstindex = -1;
        nextindex = 0;
        cap = s;
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

    void enqueue(T element)
    {
        if (size == cap)
        {
            T *newdata = new T[cap * 2];
            int j = 0;
            for (int i = firstindex; i < cap; i++)
            {
                newdata[j] = data[i];
                j++;
            }

            for (int i = 0; i < firstindex; i++)
            {
                newdata[j] = data[i];
                j++;
            }

            delete[] data;
            data = newdata;
            firstindex = 0;
            nextindex = cap;
            cap *= 2;
        }

        data[nextindex] = element;
        nextindex = (nextindex + 1) % cap;
        if (firstindex == -1)
        {
            firstindex = 0;
        }
        size++;
    }

    T front()
    {
        if (isempty())
        {
            return 0;
        }
        return data[firstindex];
    }

    T dequeue()
    {
        if (isempty())
        {
            cout << "Array empty";
            return 0;
        }
        T store = data[firstindex];
        firstindex = (firstindex + 1) % cap;
        size--;
        if (size == 0)
        {
            firstindex = -1;
            nextindex = 0;
        }

        return store;
    }
};

int main()
{
    QueUsingArrays<int> q1(4);

    q1.enqueue(92);
    q1.enqueue(2);
    q1.enqueue(721);
    q1.enqueue(3);
    q1.enqueue(413);
    q1.enqueue(413);
    q1.enqueue(4);
    cout << q1.front() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.front() << endl;
    // cout << q1.dequeue() << endl;
    // cout << q1.dequeue() << endl;
    q1.enqueue(10);
    q1.enqueue(32);
    q1.enqueue(22);
    q1.enqueue(32);
    q1.enqueue(422);
    q1.enqueue(332);
    q1.enqueue(1);
    cout << q1.front()<<endl;
    cout<<q1.getsize()<<endl;

    return 0;
}