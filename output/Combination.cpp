#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void combination(vector<int> nums, int index, int target, vector<int> subsets, vector<vector<int>> &output)
{

    if (index >= nums.size())
    {
        if (target == 0)
        {
            output.push_back(subsets);
        }
        return;
    }

    if (target >= nums[index])
    {
        subsets.push_back(nums[index]);

        combination(nums, index, target - nums[index], subsets, output);
    };
    combination(nums, index + 1, target - nums[index], subsets, output);
}

void printVectorVector(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    vector<int> nums{2, 3, 6, 7};
    int target = 7;
    vector<int> subsets;
    vector<vector<int>> output;
    int N = nums.size();
    combination(nums, 0, target, subsets, output);
    sort(subsets.begin(), subsets.end());
    printVectorVector(output);
    
    return 0;
}