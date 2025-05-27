#include <bits/stdc++.h>
using namespace std;

int help(vector<int> arr , int target){
    sort(arr.begin() , arr.end());

    int n = arr.size(), val = target , ans = 0;

    for(int i = n-1 ; i >=0 ; i++){
        int curr = arr[i];

        while (val >= curr ){
            val -= curr;
            ans++;
        }

    }

    return ans;
}


int main(){

    vector <int> arr = {9, 6, 5, 1};
    int tar = 19 ;
        int ans = help(arr , tar);

    cout<< "max candies " <<ans<<endl;

    return 0;
}
