#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0 , n = nums.size();

        for(int i = 0 ; i < 32 ; ++i){
            int cnt = 0;

            for(int j = 0 ; j < n ; ++j){

                if(nums[j]&(1 << i)) cnt++;
            }

            if(cnt%3 == 1) ans | (1 << i);
        }

        return ans;
    }
};

int main(){



    return 0;
}
