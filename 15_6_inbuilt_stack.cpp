#include "iostream"
using namespace std;
#include <stack>

int main()
{
    stack<int> s1;
    s1.push(12);
    s1.push(32);
    s1.push(22);
    s1.push(27);
    cout<<s1.top()<<endl;
    s1.pop();
    cout<<s1.size()<<endl;
    cout<<s1.empty()<<endl;
    cout<<s1.top()<<endl;
    

    

   


    return 0;
}