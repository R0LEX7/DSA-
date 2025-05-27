#include <bits/stdc++.h>
using namespace std;

long long countAlternatingSubarrays(vector<int>& arr) {
        int n = arr.size() , l = 0 , r = 1 , cnt = 0;
        long long res = 0 , mod = 1e9 +7;

        while(r<n){
            if(arr[r] != arr[r-1]){
                cnt++;
            }else{
                res  += ((cnt * (cnt + 1)) /2) % mod;
                cnt = 0;
            }
            r++;
        }
         res  += ((cnt * (cnt + 1)) /2) % mod;

        return res + n;

    }


int main(){

    vector <int> arr = {0,1,0,1};

    long long ans = countAlternatingSubarrays(arr);

    cout<<ans<<endl;

    return 0;
}
