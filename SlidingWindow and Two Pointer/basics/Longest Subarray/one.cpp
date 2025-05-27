// longest subarray with sum <= k

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> arr, int k , vector<int>& ans){
    int l = 0, r = 0, n = arr.size(), maxiLen = 0;
    int sum = 0;

    for (int i = l; i <= r; i++){
        ans.push_back(arr[i]);
        sum += arr[i];
    }

    while (r < n && l < n){

        if (sum <= k){
            maxiLen = max(maxiLen, r - l + 1);

            r++;
            if (r < n){
                ans.push_back(arr[r]);
                sum += arr[r];
            }
        }
        else{
            sum -= arr[l];
            if (!ans.empty()) ans.erase(ans.begin());
            l++;
        }
    }

    return maxiLen;
}

int main(){

    vector<int> arr = {2,5,1,10,10};
    int k = 14;

    vector <int> output ;

    int ans = longestSubarray(arr, k , output);

    cout << "longest subarray length with sum " << k << " is " << ans << endl;
    cout << "longest subarray with sum " << k << " is {";
    for(int i = 0 ; i< ans ; i++){
        cout<<output[i]<< ",";
    }
    cout<<"}"<<endl;

    return 0;
}
