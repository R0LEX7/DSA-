#include <bits/stdc++.h>
using namespace std;

int getLongestSubstring(string s){
    int l = 0 , r = 0 , n = s.size()  , maxi = -1;
        unordered_map <char , int> myMap;

    while(r<n ){
            // includes means shrink the window
            if(myMap.find(s[r]) != myMap.end()){
                l = myMap[s[r]] + 1;
                break;

            }
                // not includes means extend the window and len
            myMap[s[r]] = r;


        maxi = max(maxi, r-l+1);
        r++;



        }


    return maxi;
}


int main(){

    string str = "abba";

    int longestLen = getLongestSubstring(str);
    cout<<longestLen<<endl;

    return 0;
}
