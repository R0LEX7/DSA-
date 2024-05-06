#include <bits/stdc++.h>

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxProf = 0;
        int mini = arr[0];

        for(int i=0; i< arr.size() ; i++){
            maxProf = max(maxProf , arr[i] - mini);
            mini = min(arr[i] , mini);
        }

        return maxProf;
    }
};
