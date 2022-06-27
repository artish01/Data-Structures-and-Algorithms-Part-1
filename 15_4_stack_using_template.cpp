#include <iostream>
using namespace std;

template <typename U>

class StackUsingarrays
{
    U *data;
    int next;
    int cap;

public:
    StackUsingarrays()
    {
        data = new U[4]; // values are set using constructor
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
    void push(U element)
    {
        if (next == cap)
        {

            U *new_data = new U[cap * 2];
            for (int i = 0; i < cap; i++)
            {
                new_data[i] = data[i];
            }
            cap *= 2;

            delete[] data;
            data = new_data; // now data will point to new_data array
            // cout << "Stack full" << endl;
            // return;
        }
        data[next] = element;
        next++;
    }

    U pop()
    {
        if (isempty())
        {
            cout << "stack empty" << endl;
            return 0;
            next--;
            return data[next];
        }
    }

    U top()
    {
        if (isempty())
        {
            cout << "Stack empty" << endl;
            return 0;
        }
        return data[next - 1];
    }
};

int main()
{
    StackUsingarrays<char> s;
    s.push(5);
    s.push(15);
    s.push(4);
    s.push(8);
    s.push(122);
    s.push(120);

    cout << s.top() << endl;
    s.push(85);
    cout << s.top();

    return 0;
}
