#include <iostream>
using namespace std;

void sorted(int arr[], int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        int min = arr[i], minidx = i;
        for (int j = i + 1; j < s; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minidx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minidx];
        arr[minidx] = temp;
        for (int i = 0; i < s; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int arr[] = {3, 1, 4, 5, 9, 2, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    sorted(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}