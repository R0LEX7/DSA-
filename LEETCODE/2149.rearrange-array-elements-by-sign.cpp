/*
 * @lc app=leetcode id=2149 lang=cpp
 *
 * [2149] Rearrange Array Elements by Sign
 */

// @lc code=start
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        int ind = 0;
        int pos = 0;
        int neg = 1;
        vector<int> ans(n, -1);

        while (ind < n)
        {
            if (nums[ind] > 0)
            {
                // positive
                ans[pos] = nums[ind];
                pos += 2;
            }
            else
            {
                // negative
                ans[neg] = nums[ind];
                neg += 2;
            }
            ind++;
        }

        return ans;
    }
};
// @lc code=end
