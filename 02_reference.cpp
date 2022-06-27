#include  <iostream>
using  namespace std;

int &f(int n)  //it will give error   as function will destroy after it calls end
{
    int w;
    w = n;
    return w;

}

int *p(int l)
{
    return &l;

}

int main()
{


    int i =10;
    int &j = i;  // reference variable
    i++;
    cout<<j<<endl;


    f(i);
    int &k = f(i);

    cout<<k<<endl;

    int *g = p(i); // error 
    




    return 0;


}