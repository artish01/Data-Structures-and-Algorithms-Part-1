#include  <iostream>
using  namespace std;


int main()
{


    int a = 65;
    char b  = a;
    cout<<"the value of b is "<<b<<endl;

    int  *p = &a;
    char *c = (char*)p;

    cout<<*p<<endl;
    cout<<*(p+1)<<endl;  // bcz in int it prints random value and in char it printts null character
    cout<<*(p+2)<<endl;


    cout<<"the value of b is "<<*p<<endl; 
    cout<<"the value of p+1 is "<<*(p+1)<<endl; 
    cout<<*c<<endl;
    cout<<*(c+1)<<endl; // bcz they are stored from starting  soo c+1 = null as it is a char


    return 0;


}