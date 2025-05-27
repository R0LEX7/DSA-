#include <bits/stdc++.h>
using namespace std;

int help(vector<string>& w, string p){

    int n = p.size() , cnt = 0;

    for(string s : w ){

        if(s.size() < n) continue;
        int i ;
        for( i = 0 ; i < n ; i++){
            if(p[i] != s[i]) break;
        }
        if(i == n) cnt++;
    }

    return cnt;
}


int main(){

    vector<string> words = {"pay","attention","practice","attend"};
     string pref = "at";
    int ans = help(words , pref);
    cout<<ans;

    return 0;
}
