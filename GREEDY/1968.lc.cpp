#include <bits/stdc++.h>
using namespace std;

 vector<int> rearrangeArray(vector<int>& arr) {
    int n = arr.size();

    for(int i = 1 ; i < n ; i++){
        if(2 * arr[i] == arr[i+1] + arr[i-1]){
            swap(arr[i] , arr[i+1]);
        }
    }

    for(int i = n-2 ; i >=0 ; i--){
        if(2 * arr[i] == arr[i+1] + arr[i-1]){
            swap(arr[i] , arr[i-1]);
        }
    }

    return arr;

    }


int main(){

    return 0;
}
