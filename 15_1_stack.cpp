#include <iostream>
#include <climits>
using namespace std;

class StackUsingarrays
{
    int *data; // bcz we are creating it dynamically so it is *data 
    int next;
    int cap;

public:
    StackUsingarrays(int size)
    {
        data = new int[size];
        next = 0;
        cap = size;
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
            cout << "Stack full" << endl;
            return;
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
    StackUsingarrays s(5);
    s.push(5);
    // s.push(12);
    s.push(15);
    s.push(4);
    s.push(8);
    s.push(122);
    s.push(32);
    cout << s.top()<<endl;
    cout << s.pop()<<endl;
    cout << s.top()<<endl;
    s.push(100);
    cout<<s.top();



    return 0;
}
