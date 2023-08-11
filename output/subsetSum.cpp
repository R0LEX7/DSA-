#include<iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void subset(int index, int sum , vector<int>  &nums, vector<int> &subsets , int N  ){
    if( index >= N){
        subsets.push_back(sum);
        return;
    }
    // exclude
    subset(index + 1, sum, nums , subsets , N );
    // include
    subset(index + 1, sum + nums[index], nums , subsets , N );
}

void print(vector<int> subsets){
    for (int i = 0; i < subsets.size(); i++)
    {
       cout<<subsets[i]<<endl;
    };
    
    
}


int main()
{ 
    vector<int>  nums{3,2,1};
    vector<int> subsets;
    int N = nums.size();
    subset(0,0,nums ,subsets , N );
    sort(subsets.begin(), subsets.end());
    print(subsets);
    return 0;
}