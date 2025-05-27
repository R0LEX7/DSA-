#include <bits/stdc++.h>
using namespace std;

int maxAbsoluteSum(vector<int>& arr) {
        int n = arr.size() , maxCurr = arr[0] , maxGlobal = arr[0] , minCurr = arr[0] , minGlobal = arr[0];

        for(int i =1 ; i < n ; i++){
            int ele = arr[i];
            maxCurr = max(ele , maxCurr + ele);
            minCurr = min(ele , minCurr + ele);
            maxGlobal = max(maxGlobal , maxCurr);
            minGlobal = min(minGlobal , minCurr);
        };

        return max(maxGlobal , abs(minGlobal));
}


int main(){

    return 0;
}