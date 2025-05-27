#include <bits/stdc++.h>
using namespace std;

void generatePermutations(string s ,  string current, unordered_set<string> &unique , int index){

    if(index >= s.length()){
        if(!current.empty() && unique.find(current) == unique.end()) unique.insert(current);
        return;
    };

    // take

    generatePermutations(s, current + s[index], unique, index+1);

    // not take'
    generatePermutations(s, current, unique, index+1);

}

int fact(int n){
    if(n == 0){
        return 1;
    }
    return n*fact(n-1);
}


int numTilePossibilities(string tiles) {
        unordered_set <string> unique;
        string current = "";
        sort(tiles.begin(), tiles.end());
        generatePermutations(tiles, current, unique , 0);

        int ans = 0;

        for(string s : unique){
            unordered_map<char , int> freq;


           for(char c : s) freq[c]++;
           int deno = 1;

           for(auto p:freq) deno *= fact(p.second);
            ans += fact(s.length()) / deno;
        }

        return ans;

}


int main(){

    int ans = numTilePossibilities("AAABBC");
    cout<<ans<<endl;

    return 0;
}
