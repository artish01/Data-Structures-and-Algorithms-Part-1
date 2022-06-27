#include <iostream>
using namespace std;
#include <queue>


int main()
{

    queue<int> q1;
    q1.push(12);
    q1.push(21);
    q1.push(5);
    q1.push(1);

    cout<<q1.front()<<endl;
    q1.pop();
    cout<<q1.front()<<endl;
    cout<<q1.size()<<endl;
    cout<<q1.empty()<<endl;


     




    return 0;
}