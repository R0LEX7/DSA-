#include <bits/stdc++.h>
using namespace std;



string maximumNumber(string num, vector<int>& arr) {
    int n = num.length();

    for(int i = 0  ; i < n ; i++){
        char c = num[i];
        int ind = c - '0';

        if(c < arr[ind] ){
            num[i] = arr[ind];
        }else break;
    }

    return num;

    }


int main(){

    return 0;
}
