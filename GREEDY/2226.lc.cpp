#include <bits/stdc++.h>
using namespace std;

 int maximumCandies(vector<int>& arr, long long k) {
        long long s = 1 , e = *max_element(arr.begin() , arr.end()) , mid;

        auto check = [&](long long x){
            int candies = 0;
            for(int q : arr){
                candies += q /x;

            }
            return candies >= k;
        };

        while(s<e){
            mid = s + (e-s)/2;
            if(check(mid)) s = mid +1;
            else e = mid;
        }
        return s;
    }


int main(){

    return 0;
}