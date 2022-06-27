#include <iostream>
#include <climits>
using namespace std;

class StackUsingarrays
{
    int *data;
    int next;
    int cap;

public:
    StackUsingarrays()
    {
        data = new int[4];
        next = 0;
        cap = 4;
    }

    int size()
    {
        return next;
    }
    bool isempty()
    {
        if (next == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int element)
    {
        if (next == cap)
        {

            int *new_data = new int[cap*2];
            for(int i=0; i<cap; i++)
            {
                new_data[i] = data[i];
            }
            cap *=2;

            delete [] data;  // deleting data array wont delete array it just delete the data not array
            data = new_data; // now data will point to new_data array
            // cout << "Stack full" << endl;
            // return;
        }
        data[next] = element;
        next++;
    }

    int pop()
    {
        if (isempty())
        {
            cout << "stack empty" << endl;
            return INT_MIN;
        }
        next--;
        return data[next];
    }

    int top()
    {
        if (isempty())
        {
            cout << "Stack empty" << endl;
            return INT_MIN;
        }
        return data[next - 1];
    }
};

int main()
{
    StackUsingarrays s;
    s.push(5);
    // s.push(12);
    s.push(15);
    s.push(4);
    s.push(8);
    s.push(122);
    s.push(32);
  
    cout << s.top()<<endl;
    s.push(100);
    cout<<s.top();


    return 0;
}
