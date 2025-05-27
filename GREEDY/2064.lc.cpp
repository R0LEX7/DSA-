#include <bits/stdc++.h>
using namespace std;

bool check(int x , vector<int> quantities , int n){
    int stores = 0;

    for(int q : quantities){
        stores += (q + x - 1) / x;
        if(stores > n ) return false;
    }

    return true;
}

int minimizedMaximum(int n, vector<int>& arr) {
    int s = 0  , e = *max_element(arr.begin() , arr.end());


    while(s<e){
        int mid = s + (e-s)/2;

        if(check(mid , arr ,n)) e = mid;
        else s = mid +1;
    }
        return s;
    }


int main(){

    return 0;
}