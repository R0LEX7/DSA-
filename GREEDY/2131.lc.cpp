#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(vector<string>& words) {

    int len = 0 , odd = 0;
    unordered_map<string , int> map;
    unordered_map<string , int> mapComm;

    for(string s : words){
        map[s]++;
    }

    // for(auto [key , value] : map){
    //     string rev = string("") + key[1] + key[0];
    //     if(key[1] == key[0]) common = 1;
    //     else if(map.find(rev) != map.end() && map[key] != 0 && map[rev] != 0){
    //         int cnt = min(map[key] , map[rev]);
    //         len  += 2*cnt;
    //         map[key] = 0;
    //         map[rev] = 0;
    //     }
    // }

    for(string s : words){
        if(s[1] != s[0]){
            string rev = string("") + s[1] + s[0];
            if(map.find(rev) != map.end() && map[s] > 0 && map[rev] > 0){
                len += 4;
                map[rev]--;
                map[s]--;

            }
        }else{
            len += (map[s]/2)*4;
            if(map[s]&1) odd = 1;
            map[s] = 0;
        }
    }
        return odd > 0 ? len + 2 : len;

    }


int main(){

    return 0;
}