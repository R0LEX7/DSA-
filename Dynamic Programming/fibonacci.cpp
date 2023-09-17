#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/* memoization

int fib(int n , vector<int>& dp){
    // base case
    if(n < 2) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = fib(n-1 , dp) + fib(n-2 , dp); 
}
*/


int main(){
    int n ;
    cout<<"Enter n :"<<endl;
    cin >> n;
    // vector<int> dp(n+1 , -1);

    // int ans = fib(n, dp);
    // cout<<ans<<endl;

    int prev2 = 0 ;
    int prev = 1;
    int curr = 0 ;

    for(int i = 2; i <= n; i++){

        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    cout<<curr<<endl;

    return 0;
}