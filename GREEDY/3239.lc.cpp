#include <bits/stdc++.h>
using namespace std;

int help(vector<vector<int>> arr){
    int n = arr.size() , m = arr[0].size() , cnt1 = 0 , cnt2 = 0;

    // for rows
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m/2 ; j++){
            if(arr[i][j] != arr[i][m-j-1]) cnt1++;
        }
    }

    // for col
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n/2 ; j++){
            if(arr[j][i]!= arr[n-j-1][i]) cnt2++;
        }
    }

    return min(cnt1 , cnt2);
}


int main(){

    vector<vector<int>> arr ={{1,0,0},{0,0,0} , {0,0,1}};

    int ans = help(arr);

    cout<<ans;

    return 0;
}
