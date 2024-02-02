
#include <bits/stdc++.h>
using namespace std;

int findMex(vector<int> &arr, int n)
{

    sort(arr.begin(), arr.end());

    int ind = 0;

    int x = 0;

    while (ind < n)
    {
        if (arr[ind] >= 0)
        {
            if (arr[ind] == x)
                x++;
        }
        ind++;
    }
    return x;
}

int main()
{
    vector<int> arr = {1,0,2,4};
    int ans = findMex(arr, arr.size());
    cout << ans << endl;

    return 0;
}
