#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int help(vector<int>& arr , int index, int ans){
            if(index == arr.size()) return ans;

            // take
            int take = help(arr, index + 1, ans ^ arr[index]);
            int notTake = help(arr , index + 1, ans);

            return take + notTake;
        }
        int subsetXORSum(vector<int>& nums) {
            return help(nums, 0, 0);
        }
    };


int main(){
    vector<int> arr = {5,1,6};
    int ans = Solution().subsetXORSum(arr);
    cout<<ans;
    return 0;
}
