/**
 *992. Subarrays with K Different Integers
Hard
Topics
Companies
Hint
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.



Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 */

#include <bits/stdc++.h>
using namespace std;

int func( vector <int> arr , int k){
     int r = 0 , l = 0 , n = arr.size() , intCnt = 0 , ans = 0;
     unordered_map <int , int> map;

// Input: nums = [1,2,1,2,3], k = 2


     while (r<n){
        // not  includes
        if(map.find(arr[r]) == map.end()){
            intCnt++;
        }
        map[arr[r]] = r; // set the current item in map with latest index

        while(intCnt > k){
            if(map[arr[l]] == l){
                map.erase(arr[l]);
                intCnt--;
            }
            l++;
        }

        ans = ans + (r-l) + 1;
        r++;
     }

     return ans;
}


int main(){

    vector <int> arr = {1,2,1,2,3};
    int k = 2;

    int ans = func(arr , k) - func(arr , k-1);

    cout<<ans<<endl;

    return 0;
}
