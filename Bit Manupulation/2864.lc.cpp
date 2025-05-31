#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getSetBits(string s){
        char one = '1';
        int cnt = 0;

        for(auto ch : s){
            if(ch == one) cnt++;
        }

        return cnt;
    }
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string res(n,'0');

        int cnt = getSetBits(s) -1;

        res[n-1] = '1';

        cout<<cnt<<endl;

        for(int i = 0 ; i< n-1 ; ++i){
            if(cnt != 0 &&  cnt--){
                res[i] = '1';
                continue;
            }

            res[i] = '0';
        }

        return res;

    }
};

int main(){

    Solution sol;

    cout<<sol.maximumOddBinaryNumber("0101")<<endl;

    return 0;
}
