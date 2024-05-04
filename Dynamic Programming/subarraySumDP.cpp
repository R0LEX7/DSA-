
#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &arr, int i ,int target  , vector<vector<int>> &dp ){

	if(i == 0 ) return arr[0] == target;

	if(target == 0)  return true;

	// dp
	if(dp[i][target] != -1) return dp[i][target];

	bool notTake = helper(arr , i-1 , target , dp);

	bool take = false ;

	if(target >= arr[i]) take = helper(arr , i -1 , target - arr[i] , dp);

	return dp[i][target] = (notTake || take);
}

bool tabulation(vector<int> &arr, int n ,int target  , vector<vector<bool>> &dp){

	for(int i = 0 ; i<n ; i++) dp[i][0] = true;

	dp[0][arr[0]] = true;

	for(int i = 1 ; i < n; i++){
		for(int k = 1 ; k <=  target; k++){

			bool notTake = dp[i-1][k] ;

			bool take = false ;

			if(k >= arr[i]) take = dp[i -1][k - arr[i]];

			dp[i][k] = notTake || take;
		}
	}

	return dp[n-1][target];
}

int main(){
    freopen("inputf.txt" , "r", stdin);
    freopen("output.txt" , "w", stdout);

    cout<<"Hello from Himansh"<<endl;

    vector<int> arr = {1,2,3,4};
    int n = arr.size();
    int target = 10;
    vector<vector<bool>> dp(n , vector<bool>(target +1 , 0));

    bool ans = tabulation(arr ,n , target , dp);

    cout<<"ans " <<ans<<endl;

    return 0;
}