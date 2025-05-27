#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& arr, int k) {
       long long int n = arr.size() , r=0 , l = 0 , maxi = 0 , sum = 0 ;
        sort(arr.begin(),arr.end());

        while(r<n){
            sum += arr[r];

            if((r-l+1*arr[r] > sum + k) && l+1 <=r){
                sum -= arr[l];
                l++;
            }

            maxi = max(maxi , r-l+1);
            r++;
        }



        return maxi;
}


int main(){

    return 0;
}
