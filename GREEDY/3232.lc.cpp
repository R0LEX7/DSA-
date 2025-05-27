#include <bits/stdc++.h>
using namespace std;

bool help(vector <int> arr){
    int n = arr.size() , singleSum = 0 , doubleSum = 0;

    for(int x:arr){
        if(x < 10) singleSum += x;
        else doubleSum += x;
    };

    return singleSum != doubleSum;
}


int main(){

    return 0;
}
