#include <bits/stdc++.h>
using namespace std;

int help (string s){
    int n = s.size()  , l = 0 , r = 0 , k = 2 , maxi = INT_MIN;

    unordered_map <char , int> map;

    while(r<n){
        map[s[r]]++;


        if(map[s[r]] > k) {
            while(map[s[r]] > k){
               map[s[l]]--;
                l++;
            }
        }
        maxi = max(maxi , r - l + 1);
        r++;
    }

    return maxi;
}


int main(){

    string s = "aaaa";

    int ans = help(s);

    cout<<ans<<endl;

    return 0;
}
