#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> nextGreater(vector<int> &arr, int n) {

        stack <int> st;
        int max = INT_MAX;
        st.push(max);
        vector<int> ans(n);

        for(int i = n - 1 ; i>=0 ; i--){
            int curr = arr[i];

            while(st.top()<=curr){
                st.pop();
            };
            if(st.top() == max){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(curr);
        };

        return ans;
    }
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
          int n = nums2.size();
        vector <int> nextgreaterArr =  nextGreater(nums2, n);

        unordered_map<int, int> mp;

        for(int i = 0 ; i<n ; i++){
            mp[nums2[i]] = nextgreaterArr[i];
        }

        for(int i = 0 ; i<nums1.size() ; i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    };

};


int main(){

    return 0;
}