#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c ){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    return 0;
}

bool help(string s){
    int cnt = 0;

    for(char c : s){
        if(isVowel(c)) cnt++;
        if(cnt > 0) return true;
    }

    return false;
}


int main(){

    return 0;
}
