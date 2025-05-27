#include <bits/stdc++.h>
using namespace std;

int help(vector<int> arr, int k)
{
    int n = arr.size(), mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = i; j < n; j++)
        {
            temp.push_back(arr[j]);
        }

        int x = 0 , m = static_cast<int>(temp.size());

        for (int i = 0; i < m; i++)
        {
             x |= temp[i];
        }
        if (x >= k){
            mini = min(mini,m );
        }
    }

    return (mini == INT_MAX) ? -1 : mini;
}

int main()
{
    vector<int> arr = {2,1,8};

    int ans = help(arr , 11);

    cout<<ans<<endl;

    return 0;
}
