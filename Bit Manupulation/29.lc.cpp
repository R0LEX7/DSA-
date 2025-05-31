#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend == divisor) return 1;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long ans = 0;



        while(n >= d){
            int cnt = 0;

            while(n >= (d <<(cnt+1))){
                cnt++;
            }
            ans += 1<<(cnt+1);

            n -= d << (cnt+1);
        }

        if(ans == (1<<31) && sign == 1) return INT_MAX;
        if(ans == (1<<31) && sign == -1) return INT_MIN;

        return sign * ans;
    }
};

int main(){

    return 0;
}