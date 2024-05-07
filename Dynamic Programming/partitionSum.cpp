
#include <bits/stdc++.h>
using namespace std;

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

    cout<<"Hello from Himanshu"<<endl;

    vector<int> arr = {1,2,5};

    int totalSum = 0;

    for(int x : arr){
    	totalSum += x;
    }


    if(totalSum &1) cout<<false<<endl;

    int target = totalSum/2;

    cout<<target<<endl;


    vector<vector<bool>> dp(arr.size() , vector<bool>(target + 1 , 0));

    bool ans = tabulation(arr ,arr.size() , target ,dp );

    cout<<ans<<endl;

    return 0;
}