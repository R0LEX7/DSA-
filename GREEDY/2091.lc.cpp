#include <bits/stdc++.h>
using namespace std;

    int minimumDeletions(vector<int>& arr) {
        int  n = arr.size() , mini = INT_MAX , maxi = INT_MIN , i1 = 0 , i2 = 0;

        if(n==1) return 1;

        // find max ans mini
        for(int i = 1 ; i < n+1 ; i++){
            if(arr[i-1] > maxi){
                maxi = arr[i-1];
                i1 = i;
            }
            if(arr[i-1] < mini){
                mini = arr[i-1];
                i2 = i;
          }
        }

        return min( min(max(i1 , i2) , max(n-i1 +1 , n-i2 +1)) , (i1 + (n-i2+1) ) );

    }


int main(){

    return 0;
}