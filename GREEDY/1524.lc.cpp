#include <bits/stdc++.h>
using namespace std;

int help(vector<int> arr)
{
    int n = arr.size(), cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum & 1)
                cnt++;
        }
    }
    return cnt;
}

int main()
{

    int ans = help({1,2,3,4,5,6,7});
    cout << ans << endl;

    return 0;
}
