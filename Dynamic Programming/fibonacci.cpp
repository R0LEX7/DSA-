#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int fib(int n , vector<int>& dp){
    // base case
    if(n < 2) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = fib(n-1 , dp) + fib(n-2 , dp); 
}


int main(){
    int n ;
    cout<<"Enter n :"<<endl;
    cin >> n;
    vector<int> dp(n+1 , -1);

    int ans = fib(n, dp);
    cout<<ans<<endl;

    return 0;
}