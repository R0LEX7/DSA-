// L4. Max Consecutive Ones III | 2 Pointers and Sliding Window Playlist


#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> arr , int k){
    int l = 0 , r = 0 , n = arr.size() , zeroes = 0 , maxi = 0;

    while (r<n){

        if(arr[r] == 0) zeroes++;
        if(zeroes > k && arr[l] == 0){
             zeroes--;
             l++;
             }

        if(k < zeroes)l++;
        else maxi = max(maxi , r-l+1);
        r++;
    }
    return maxi;
}


int main(){

    vector<int> arr = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;

    int ans = maxConsecutiveOnes(arr , k);

    cout<<"Max Consecutive Ones "<<ans<<endl;
    if(0<0){
        cout<<"yes"<<endl;
    }

    return 0;
}
