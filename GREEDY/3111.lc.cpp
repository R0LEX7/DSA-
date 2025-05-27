#include <bits/stdc++.h>
using namespace std;

int minRectanglesToCoverPoints(vector<vector<int>>& arr, int w) {

    sort(arr.begin() , arr.end() , [](vector<int> &a ,  vector<int> &b ){
        return a[0] < b[0];
    });

    int x= arr[0][0] , cnt = 1;

    for(vector<int> a : arr){
        if(a[0] > x + w){
            x = a[0];
            cnt++;
        }
    }

    return cnt;
}


int main(){

    return 0;
}
