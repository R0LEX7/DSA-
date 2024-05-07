
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &arr , int n , int s
	){
	int prev2 = 0;
	int prev = arr[s];

	for(int i =s +1 ;i< n ; i++){

		int take = (i > 1 ? prev2 + arr[i] : arr[i]);

		int notTake = 0 + prev;

		int curr = max(take , notTake);

		prev2 = prev ;
		prev = curr;

	}
	return prev;
}


int main(){
    freopen("inputf.txt" , "r", stdin);
    freopen("output.txt" , "w", stdout);

    cout<<"Hello from Himanshu"<<endl;

    vector<int> arr = {1,2,3};

    int n = arr.size();

    int res1 = helper(arr , n-1 , 0);

    int res2= helper(arr , n , 1);

    int ans = max(res1 , res2);

    cout<<"max = " << ans<<endl;


    return 0;
}