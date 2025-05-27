#include <bits/stdc++.h>
using namespace std;

  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int n = rowSum.size();
    vector<vector<int>> ans(n , vector<int>(n , -1));

    for( int i = 0 ; i < n ; i++){

        for(int j = 0 ; j < n ; j++){
            int x = min(rowSum[i] , colSum[j]);
            ans[i][j] = x;
            rowSum[i] -= x;
            colSum[j] -= x;
        }
    }

    return ans;
    }


int main(){

    return 0;
}