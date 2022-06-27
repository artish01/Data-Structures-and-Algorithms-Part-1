#include  <iostream>
#include  <climits>
using  namespace std;


int main()
{


    // int *a = new int;
    // *a = 322;
    // cout<<*a<<endl;
    // cout<<&a<<endl;
    // cout<<a<<endl;
d
    // delete a;

    // cout<<*a<<endl;  // it will gives garbage value as  a is deleted 
    // *a=44;
    // cout<<a<<endl;
    // cout<<&a<<endl;

    // dynamic array
    int n;
    cout<<"enter the size of array ";
    cin>>n;

    int *arr = new int[n];
    int max = INT_MIN;

     for(int i=0; i<n; i++)
    {
        cout<<"Enter the "<<i+1<<" element of the array ";
        cin>>arr[i];
    }
    // delete [] arr;  // now the max number will give a garbage value as i have deleted the array

    for(int i=0; i<n; i++)
    {
        if(arr[i]>max)
        {
            max= arr[i];
        }
        
    }
    cout<<"The max number in array is "<<max<<endl;

    delete [] arr;

    arr= new int[n];  // reallocating after deleting the memory






    return 0;


}
