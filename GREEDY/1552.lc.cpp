#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<int>& arr, int m) {
    sort(arr.begin() , arr.end());
    int n = arr.size() , s = 0 , e = arr[n-1]  , ans = -1 ;

    auto check = [&](int x) -> bool {
        int cnt = 1 , prv = 0;

        for(int i = 1 ; i < n ; i++){
            if(arr[i] - arr[prv] >= x){
                cnt++;
                prv = i;
            }
        }
        return cnt >= m;
    };


    while(s<=e){
        int mid = s + (e-s)/2;
        if(check(mid)){
            ans = mid;
            s = mid+1;
        }else e = mid - 1;
    }

    return ans;
    }



int main(){

    return 0;
}