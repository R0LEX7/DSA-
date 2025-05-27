#include <bits/stdc++.h>
using namespace std;

    string largestNumber(vector<int>& nums) {

        vector<string> str;

        for(int x : nums){
            str.push_back(to_string(x));
        };

        sort(str.begin() , str.end() , [](string &a , string &b){
            return (b + a) < (a+b);
        });

        if(str[0] == "0") return "0";
        string ans = "";

        for(string s : str) {
            ans += s;
        }
    return ans;

    }


int main(){

    return 0;
}