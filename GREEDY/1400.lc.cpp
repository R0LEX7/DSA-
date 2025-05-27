#include <bits/stdc++.h>
using namespace std;

bool help(string s , int k){

    int oddCnt = 0;

    unordered_map<char , int> map;

    for(char c : s){
        map[c]++;
        if(map[c]&1) oddCnt++;
        else oddCnt--;
    }

    return oddCnt <= k && s.size() >= k;
}


int main(){

    return 0;
}
