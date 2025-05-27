#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& arr) {
            set<int> ds;

            for(int x : arr) ds.insert(x);

            int distinct = ds.size() , ans = 0 , n = arr.size();

            for(int i = 0 ; i < n ; ++i){
                set<int> unique ;
                // int cnt = 1;

                for(int j = i ; j < n; ++j){
                    if(unique.count(arr[j]) == 0) unique.insert(arr[j]);

                    if(unique.size() == distinct){
                        ans++;
                    }
                }
            }

            return ans;
        }
    };


int main(){

    Solution sol;
    vector<int> arr = {5,5,5,5};

    int ans = sol.countCompleteSubarrays(arr);

    cout<<ans<<endl;

    return 0;
}