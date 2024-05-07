
#include <bits/stdc++.h>
using namespace std;

int mod =(int)1e9+7;
int f(int i , vector<int> arr, int target, vector<vector<int>> &dp){
	// base cases
	if(i == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    // if memo exixts
    if(dp[i][target] != -1) return dp[i][target];
	// exclude
	int exclude = f(i-1 , arr , target , dp);
	// include
	int include = 0;
	if(arr[i] <= target) include = f(i-1 , arr , target-arr[i] , dp);

	return dp[i][target] =  (include + exclude)%mod;
}

int main(){
    freopen("inputf.txt" , "r", stdin);
    freopen("output.txt" , "w", stdout);

    cout<<"Hello from Himanshu"<<endl;

    vector<int> arr = {5,2,6,4};
    int d = 3;

    int totalSum = accumulate(arr.begin() , arr.end() , 0);

    cout << totalSum<<endl;

    if(totalSum - d & 1) cout<< "false"<<endl;
    else{
    int target = (totalSum - d ) /2;
    vector<vector<int>> dp(arr.size() -1 , vector<int>(target + 1 , -1));
    cout << target<<endl;
		int ans = f(arr.size()-1 , arr , target , dp);
		cout<<" possible subsets  :"<<ans<<endl;     	
    }

    return 0;
}