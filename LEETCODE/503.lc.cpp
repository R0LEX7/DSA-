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

        while(st.top() <= arr.back()){
            st.pop();
        }

        arr.back() = st.top();

        return ans;
    }
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        return  nextGreater(arr, n);
    }

};


int main(){

    return 0;
}
