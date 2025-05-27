/**
 * 485. Max Consecutive Ones
Easy
Topics
Companies
Hint
Given a binary array nums, return the maximum number of consecutive 1's in the array.



Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 */

#include <bits/stdc++.h>
using namespace std;

int maxConsOnes(vector<int> arr){
    int maxi = 0 , l = 0 , r = 0 , n = arr.size();

    while(r<n){
        if(!arr[r]){
            l = r + 1;
        }else{
            maxi = max(maxi , r-l+1);
        }
        r++;
    }

    return maxi;
}


int main(){

vector <int> arr = {1,0,1,1,0,1};

int ans = maxConsOnes(arr);

    cout<<"Max Consecutive Ones "<<ans<<endl;

    return 0;
}
