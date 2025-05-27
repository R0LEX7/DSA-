#include <bits/stdc++.h>
using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix) {
            long long sum = 0;
            int negCnt= 0;
            long long negSum = 0;
            int mini = INT_MAX;

        for(vector<int> arr : matrix){
            for(int x : arr){
                if(x<0){
                    negCnt ++;
                    mini = min(mini , abs(x));
                }

                sum += abs(x);
            }
        }



        return negCnt%2 == 0 ? sum : sum - mini;
}

int main(){

    return 0;
}
