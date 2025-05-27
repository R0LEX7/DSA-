#include <bits/stdc++.h>
using namespace std;

    int numSplits(string s) {
        int n = 0;
        unordered_map <char , int> m1;
        unordered_map <char , int> m2;

        for(char c : s) m1[c]++;

        for(char c : s){
            m2[c]++;
            m1[c]--;
            if(m1[c] <= 0) m1.erase(c);

            if(m1.size() == m2.size()) n++;
        }

        return n;
    }


int main(){

    string s = "abcd";
    int ans = numSplits(s);

    cout<<ans<<endl;

    return 0;
}
