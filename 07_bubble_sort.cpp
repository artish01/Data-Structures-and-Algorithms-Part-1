#include <iostream>
using namespace std;

void sort(int arr[], int n)

// // best case 0(n)
// {
//     bool a = 1;
//     for (int i = 0; i < n - 1 && a; i++)
//     {
//         a = 0;

//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int tmp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = tmp;
//                 a = 1;
//             }
//         }

//     }

// }

// normal 0(n^2)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
       
        
    }
}

int main()
{

    
    int arr[] = {33, 51, 27, 85, 66, 23, 13, 57};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}