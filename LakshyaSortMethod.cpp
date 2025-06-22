#include <iostream>

using namespace std;

void printArray(int arr[], int h)
{
    int i = 0;
    cout << "\n { ";
    while (i <= h)
    {
        if (i <= h && i > 0)
            cout << ", ";
        cout << arr[i];
        i++;
    }
    cout << " }" << endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int largestNumber(int a[], int h)
{
    int large = a[0], i = 0;
    for (i = 0; i <= h; i++)
    {
        if (a[i] > large)
        {
            large = a[i];
        }
    }
    for (i = 0; i <= h; i++)
    {
        if (large == a[i])
        {
            break;
        }
    }
    return i;
}

void LakshyaSort(int arr[], int l, int h)
{
    int i;

    if (l < h)
    {
        i = largestNumber(arr, h);
        swap(&arr[i], &arr[h]);
        LakshyaSort(arr, l, h - 1);
    }
}

int main()
{
    int i = 0, ARRsize;
    cout << " Enter the size of an array: " << endl;
    cin >> ARRsize;
    int arr[ARRsize];

    cout << "---------------------------------------------------------" << endl;

    cout << " Enter an array: " << endl;
    for (i; i < ARRsize; i++)
    {
        cout << "arr[ " << i << " ] = ";
        cin >> arr[i];
    }

    cout << "---------------------------------------------------------" << endl;
    cout << " The original array: " << endl;
    int h = sizeof(arr) / sizeof(arr[ARRsize]), l = 0;
    printArray(arr, h - 1);

    LakshyaSort(arr, l, h - 1);

    cout << "=========================================================" << endl;

    cout << " The sorted array: " << endl;
    printArray(arr, h - 1);

    return 0;
}
