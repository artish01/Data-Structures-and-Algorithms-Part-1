#include  <iostream>
using  namespace std;



int binary(int arr[],int n,int a)
{
    

    int low = 0;
    int high = n-1;
    int mid = low+high/2;
    while(low<=high)
    {
        if(arr[mid]==a)
        {
            return mid;
        }
        if(arr[mid]>a)
        {
            high = mid-1;

        }
        else{
            low = mid+1;
        }
    }
    return -1;
}






int main()
{


    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++)
    {
       cin>>arr[i];
   }
   cout<<"Enter number you wish to find ";
   int a;
   cin>>a;

   cout<<binary(arr,n,a);


    return 0;


}