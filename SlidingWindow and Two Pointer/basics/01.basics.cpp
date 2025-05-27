#include <bits/stdc++.h>
using namespace std;

int getMaxSum(vector<int> arr, int k)
{
    int l = 0, r = k - 1, n = arr.size();

    int maxi = INT_MIN;

    while (r < n)
    {
        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            sum += arr[i];
        }
        maxi = max(maxi, sum);
        l++;
        r++;
    }

    return maxi;
}

int main()
{
    vector<int> arr = {-1,2,3,3,4,5,-1};

    int k =4;

    int maxSum = getMaxSum(arr , k);

    cout<<"Max Sum "<< maxSum<<endl;

    return 0;
}
