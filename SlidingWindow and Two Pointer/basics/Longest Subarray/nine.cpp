#include <bits/stdc++.h>
using namespace std;

int func(vector <int> arr , int k){
    int r = 0 , l = 0 , n = arr.size() , cnt = 0 , ans = 0;

    while(r<n){
        if(arr[r]&1) cnt++;

        while(cnt == k){
            if(arr[l]&1) cnt--;
            ans++;
            l++;
        }
        r++;
    }
    return ans;
}


int main(){

    vector<int> arr = {2,1,1,2,1,1};

    int ans = func(arr , 3);

    cout<<ans<<endl;

    return 0;
}
