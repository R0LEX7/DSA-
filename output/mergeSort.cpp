#include <iostream>
using namespace std;

void merge(int arr[], int start, int end)
{
    int mid = (start + end) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *sec = new int[len2];

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[start + i];
    }
    for (int j = 0; j < len2; j++)
    {
        sec[j] = arr[mid + 1 + j];
    }

    // index of subarrays 1 and 2 ;
    int i1 = 0;
    int i2 = 0;

    int indexOfMergedArr = start;

    while (i1 < len1 && i2 < len2)
    {

        if (first[i1] < sec[i2])
        {
            arr[indexOfMergedArr++] = first[i1++];
        }
        else
        {
            arr[indexOfMergedArr++] = sec[i2++];
        }
    }

    while (i1 < len1)
    {

        arr[indexOfMergedArr++] = first[i1++];
    }

    while (i2 < len2)
    {
        arr[indexOfMergedArr++] = sec[i2++];
    }

    delete []first;
    delete []sec;

}

void mergeSort(int arr[], int start, int end)
{

    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    // left part
    mergeSort(arr, start, mid);
    // right part
    mergeSort(arr, mid + 1, end);

    // merge
    merge(arr, start, end);
}

int main()
{
    int arr[] = {8, 5, 9, 19, 10, 3, 45, 5, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int s = 0;
    int e = size - 1;

    mergeSort(arr, s, e);
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}