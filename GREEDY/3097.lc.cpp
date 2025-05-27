#include <bits/stdc++.h>
using namespace std;

int help(vector<int> arr, int k)
{
    int n = arr.size(), x = 0, r = 0, l = 0, mini = INT_MAX;

    while (r < n)
    {
        x |= arr[r];

        if (x >= k)
        {
            mini = min(mini, r - l + 1);
            while (x >= k && l <= r)
            {
                mini = min(mini, r - l + 1);
                x &= ~(arr[l]);              // Remove `arr[l]` from OR (reset bit)
                l++;
            }


        }

        r++;
    }

   return (mini == INT_MAX) ? -1 : mini;
}

int main()
{

    vector<int> arr = {1, 2, 3};

    int ans = help(arr, 2);

    cout << ans << endl;

    return 0;
}
