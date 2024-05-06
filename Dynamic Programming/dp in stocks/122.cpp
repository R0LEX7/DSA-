#include <bits/stdc++.h>

class Solution {
int f(int i , int buy , vector<int>& arr , vector<vector<int>>& dp){
    // base case
    if(i == arr.size() ) return 0;

    // dp check
    if(dp[i][buy] != -1) return  dp[i][buy];

    if(buy){
        return dp[i][buy] = max(-arr[i] + f(i+1 , 0 , arr , dp) ,f(i+1 , 1 , arr , dp));
    }else {
        return dp[i][buy] =  max(arr[i] + f(i+1 , 1, arr , dp) ,f(i+1 , 0, arr, dp));
    }
}

int tab(vector<int>& arr ){

    int n = arr.size();

    vector<vector<int>> dp(n+1 , vector<int>(2 ,-1));

    dp[n][0] = dp[n][1] = 0;
    int prof;

    for(int i = n-1 ; i >=0 ; i--){
        for(int buy = 0 ; buy <= 1; buy++){
            if(!buy) prof = max(-arr[i] + dp[i+1][1] ,dp[i+1][0]);
            else prof =  max(arr[i] + dp[i+1][0] ,dp[i+1][1]);

            dp[i][buy] = prof;
        }
    }

    return dp[0][0];
}

public:
    int maxProfit(vector<int>& prices) {
    //     int n= prices.size();
    //     vector<vector<int>> dp(n , vector<int>(2 , -1));
    //   return f(0,1,prices , dp);

    return tab(prices);
    }
};
