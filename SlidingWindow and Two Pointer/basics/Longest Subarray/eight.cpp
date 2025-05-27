/**
 *
 * 1358. Number of Substrings Containing All Three Characters
Medium
Topics
Companies
Hint
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.



Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".
Example 3:

Input: s = "abc"
Output: 1
 */

#include <bits/stdc++.h>
using namespace std;

bool isValidSubstring(unordered_map <char , int> map ){
    if(map['a'] > 0 && map['b'] > 0 && map['c'] > 0 ) return 1;
    return 0;
}

int getSubstrings(string str){
    int l = 0 , r = 0 , n = str.size() , cnt = 0;

    unordered_map <char , int> map  = {
        {'a' , 0}, {'b' , 0}, { 'c', 0}
    };

    while (r< n){
        map[str[r]]++;

        while(isValidSubstring(map )) {
            cnt = cnt + (n-r);
            cout<<"true for l "<< l <<map['a'] << map['b'] << map['c'] <<endl;
            map[str[l]]--;
            l++;
        }
        r++;

    }
    return cnt;
}


int main(){

    string s = "abcabc";

    int ans = getSubstrings(s);

    cout<<ans<<endl;

    return 0;
}
