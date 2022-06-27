#include  <iostream>
using  namespace std;


int main()
{
    int n;
    cout<<"enter size ";
    cin>>n;


    int **arr= new int *[n];  // here rows has declared 

    for(int i=0; i<n; i++)
    {
        arr[i] = new int[3];  // coloumn has declared

        for(int j=0; j<3; j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

     for(int i=0;i<n; i++)
    {

        delete [] arr[i]      // delete the array which is placed on arr[i]   where i =1,2,3,4/..............
    }

    delete [] arr; //delete pointer;




    return 0;


}