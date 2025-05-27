#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0 , low = INT_MAX , cnt = 0;

        for(auto& el : nums){
            if((el^k) > el){
                sum += el^k;
                cnt++;
                low = min(low , (long long)(el^k - el));
            }else{
                sum += el;
                low = min(low , (long long)(el - el^k));
            }
        }

        return cnt&1 ? sum - low : sum;
    }
};

int main(){

    return 0;
}