#include <bits/stdc++.h>
using namespace std;

int help(vector<int> arr){
    int n = arr.size() , min = INT_MAX , aCnt = 0;

    for(int i = 0 ; i < n ; i++){
        arr[i] = arr[i] ? 1 : -1;
    }

    int total = 0;

     for(int i = 0 ; i < n ; i++){
        total += arr[i];
    }


    for(int i = 0 ; i < n -1 ; i++){
        aCnt += arr[i];
        if(aCnt > total - aCnt ) return i+1;
    }
    return -1;
}


int main(){

    vector <int> arr = {0,0,0};

    int ans = help(arr);

    cout<<ans;

    return 0;
}
