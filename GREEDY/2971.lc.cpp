#include <bits/stdc++.h>
using namespace std;

long long largestPerimeter(vector<int>& arr) {
        long long sideSum = 0 , prefixSum = accumulate(arr.begin() , arr.end() , 0);

        sort(arr.begin() , arr.end());
        int n = arr.size();

        for(int i =n-1 ; i >=0 ; i++){
            if(i+1 == 3) break;
            prefixSum -= arr[i];
            if(arr[i] < prefixSum){
                return arr[i] + prefixSum;
            }
        }
        return -1;
    }


int main(){

    return 0;
}