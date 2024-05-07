#include <bits/stdc++.h>

class Solution {
private:
int f(int i , int buy , int cap, vector<int>& arr , vector<vector<vector<int>>>& dp){
    // base case
    if(i == arr.size() || cap == 0 ) return 0;

    // dp check
    if(dp[i][buy][cap] != -1) {

        return  dp[i][buy][cap];
    };

    if(buy){
        return dp[i][buy][cap] = max(-arr[i] + f(i+1 , 0, cap  , arr , dp) ,f(i+1 , 1 , cap , arr  , dp));
    }else {
        int newCap = cap-1;
        return dp[i][buy][cap] =  max(arr[i] + f(i+1 , 1 , newCap, arr , dp) ,f(i+1 , 0 , cap, arr, dp));
    }
}
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
         vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(3,-1)));
        return f(0 , 1 , 2 , prices , dp);
    }
};
