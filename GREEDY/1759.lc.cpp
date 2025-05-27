#include <bits/stdc++.h>
using namespace std;

    int countHomogenous(string s) {
     int n = s.length();
        long long count = 1, result = 0, mod = 1e9 + 7;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                result = (result + (count * (count + 1)) / 2) % mod;
                count = 1;
            }
        }

        // Add the last segment
        result = (result + (count * (count + 1)) / 2) % mod;

        return result;
    }


int main(){

    return 0;
}