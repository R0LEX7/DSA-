#include <bits/stdc++.h>
using namespace std;

int help(vector<string>& words, string s){

    int cnt = words.size();

    for(string str : words){

        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] != s[i]){
                cnt--;
                break;
            }
        }
    }

    return cnt;
}


int main(){

    return 0;
}
