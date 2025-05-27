#include <bits/stdc++.h>
using namespace std;

string help( string s){
    int n = s.size();
    int freq[26] = {0};
    for(char c : s){
        if(c != '?') freq[c-'a']++;
    }

    vector <char> chars ;

    for(char c : s){
        if(c == '?'){
            int minInd = 0;

            for (int i = 0; i < 26; i++){
               if(freq[i] < freq[minInd]) minInd = i;
            }
        char ch = minInd + 'a';

        chars.push_back(ch);
        freq[minInd]++;
        }
    }

    sort(chars.begin() , chars.end());
    int j = 0;
    for (int i = 0; i < n; i++){
               if(s[i] == '?') s[i] = chars[j++];
            }

            return s;
}


int main(){

    string s = "?a??";

    string ans = help(s);

    cout<<ans<<endl;

    return 0;
}
