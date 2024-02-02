#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> arr, int n)
{
    int x = arr[0];

    for (int i = 1; i < n; i++)
    {
        x = x ^ arr[i];
    }

    return x;
}

int main()
{
    vector<int> arr = {1, 1, 2, 3 , 3 , 2 , 5};

    int ans = singleNumber(arr, arr.size());

    cout << "single Number: " << endl;
    cout << ans << endl;


    return 0;
}
