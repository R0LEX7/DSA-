#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key, int i)
{

    if (size <= i)
    {
        return -1;
    }

    if (arr[i] == key)
    {
        return i;
    }else
    {
        linearSearch(arr, size, key, i + 1);
    };
};

int main()
{
    int arr[11] = {-5, 1, 2, 3, 4, 5, 16, 17, 18, 19, 110};

    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 19;
    int i = 0;

    int ans = linearSearch(arr, size, key, i);

    cout << ans << endl;

    return 0;
}