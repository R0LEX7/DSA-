#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool hasSameDigits(string s) {
            vector<int> ans ;

            for(char ch : s){
                ans.push_back(ch - '0');
            }

            while(ans.size() != 2){
                vector<int> temp;
                for(int i = 0 ; i < ans.size() -1 ; i++){
                    int x = ans[i]  , y = ans[i+1];
                    temp.push_back((x+y)%10);
                }
                ans = temp;
            }

            return ans[0] == ans[1];
        }
    };


int main(){

    return 0;
}