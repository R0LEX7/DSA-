#include <bits/stdc++.h>
using namespace std;

int help(string s){
    int n = s.size() ,  ans = 0 , oddCnt = 0;
    unordered_map <char , int> map;

    for(char c : s){
        map[c]++;
        if(map[c]&1)  oddCnt ++;
        else oddCnt--;

    }

    return (oddCnt > 1) ? n - oddCnt + 1 : n;


}


int main(){

    return 0;
}
