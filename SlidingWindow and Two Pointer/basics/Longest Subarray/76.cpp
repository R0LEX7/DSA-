/**
 * 76. Minimum Window Substring
Hard
Topics
Companies
Hint
Given two strings s and t of lengths m and n respectively, return the minimum window
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 */

#include <bits/stdc++.h>
using namespace std;

string func(string s , string t){
    int sInd = -1 , minLen = INT_MAX , l = 0 , r = 0 , m = s.size() , n = t.size(), cnt = 0;

    unordered_map  <char , int> map;

    for(int i = 0 ; i < n ; i++) map[t[i]]++;

    while(r<m){
        if(map[s[r]] > 0) cnt++;
        map[s[r]]--;

        while(cnt == n){
            int currLen = r - l + 1;

            if(currLen < minLen){
                minLen = currLen;
                sInd = l;
            }
            map[s[l]]++;
            if(map[s[l]] > 0) cnt--;
            l++;
        }

        r++;
    }

    return sInd == -1 ? "" : s.substr(sInd , minLen);

}


int main(){

    string s = "ADOBECODEBANC", t = "ABC" ;
    string ans = func(s , t);
    for(char x : ans)cout<<x<<endl;

    return 0;
}
