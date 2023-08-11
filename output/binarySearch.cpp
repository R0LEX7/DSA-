#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{

    if (size == 0 || size == 1)
        return true;

    if (arr[0] <= arr[1])
    {
        return isSorted(arr + 1, size - 1);
    }

    return false;
}

int binarySearch(int arr[], int key, int start, int end)
{

    if (start > end)
    {
        return -1;
    };

    int mid = (start + end) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] < key)
    {
        return binarySearch(arr, key, mid + 1, end);
    }
    else
    {
        return binarySearch(arr, key, start, mid - 1);
    };
}

int main()
{

    int arr[11] = {-5, 1, 2, 3, 4, 5, 16, 17, 18, 19, 110};
    int start = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    int end = size - 1;

    if (!isSorted(arr, size))
    {
        cout << "array is not sorted" << endl;
    }
    else
    {
        int ans = binarySearch(arr, -2, start, end);
        cout << ans << endl;
    }

    //  cout << end << endl;

    return 0;
}