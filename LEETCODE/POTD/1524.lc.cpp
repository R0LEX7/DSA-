#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int rec(vector<int> &arr , int &sum , int &ans , int ind){
            if(ind >= arr.size()){
                return ans;
            }

            sum += arr[ind];
            if(sum &1) ans++;

           ans +=  rec(arr , sum , ans , ind+1);
        }
        int numOfSubarrays(vector<int>& arr) {
            int ans = 0;
            int sum = 0;


            for( int i = 0 ; i < arr.size() ; i++){
                rec(arr , sum , ans , i);
            }

            return ans;
        }
    };


int main(){

    return 0;
}