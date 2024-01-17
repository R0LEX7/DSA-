class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int cnt1 = 0, cnt2 = 0, n = nums.size(), elem1, elem2;


            for (int i = 0; i < n; i++) {
                if (cnt1 == 0 && elem2 != nums[i]) {
                    cnt1++;
                    elem1 = nums[i];
                } else if (cnt2 == 0 && elem1 != nums[i]) {
                    cnt2++;
                    elem2 = nums[i];
                } else if (elem1 == nums[i]) {
                    cnt1++;
                } else if (elem2 == nums[i]) {
                    cnt2++;
                } else {
                    cnt1--;
                    cnt2--;
                }
            }

        int cnt3 = 0, cnt4 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == elem1) {
                cnt3++;

            } else if (nums[i] == elem2) {
                cnt4++;
            }
        }

        int min = (int)(n / 3) + 1;
        if (cnt3 > n / 3) {
            ans.push_back(elem1);
        };
        if (cnt4 > n / 3) {
            ans.push_back(elem2);
        };
        sort(ans.begin() , ans.end());
        return ans;
    }
};
