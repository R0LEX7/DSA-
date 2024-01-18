class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int cnt = 0;
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int rem = prefixSum - k;
            cnt += mpp[rem];
            mpp[prefixSum]++;
        }

        return cnt;
    }
};
