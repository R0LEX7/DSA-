/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int n = nums.size();
        int s1 = n * (n + 1) / 2;
        int s2 = 0;
        for (auto& x : nums) {
            s2 += x;
        }

        return s1 - s2;
    }
};
// @lc code=end
