#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorVal = 0;

        for(int x: nums){ xorVal = xorVal^x;};

        int b1 = 0 , b2 = 0;
        long long rightMost = xorVal & ~xorVal;

        for(int x :  nums){

            if(x&rightMost) b1 = b1^x;
            else b2 = b2^x;
        }

        return {b1,b2};
    }
};

int main(){

    return 0;
}
