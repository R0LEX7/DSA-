#include <bits/stdc++.h>
using namespace std;

int addRungs(vector<int> &arr, int dist)
{

    int n = arr.size(), s = 0, last = arr[n - 1], cnt = 0, i = 0;

    while (s < last)
    {
        if (s + dist >= arr[i])
        {
            i++;
            s = s + dist;
        }

        else
        {
            cnt++;
            s = arr[i];
        }
    }

    return cnt;
}

int main()
{

    return 0;
}
