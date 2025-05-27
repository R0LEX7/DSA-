#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPrime(int a){
        if(a < 2) return 0;

        for(int i = 2 ; i*i < a ; ++i){
            if(a%i == 0) return 0;
        };

        return 1;
    };

    vector<int> findPrimeSubstring(string s){
        vector<string> allSubstrings;
        vector<int> allPrimeSubstrings;
        int n = s.size();

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j<n ; ++j) allSubstrings.push_back(s.substr(i , j-i+1));
        }

        for(string str : allSubstrings){
            int val = stoi(str);
            if(isPrime(val)) allPrimeSubstrings.push_back(val);
        }

        sort(allPrimeSubstrings.begin() , allPrimeSubstrings.end());

        return allPrimeSubstrings;
    }

public:
    long long sumOfLargestPrimes(string s) {

        vector<int> primeStr = findPrimeSubstring(s);

        long long ans = 0 , n = primeStr.size() , start = max(0 , n-3);

        for(int i = start ; i < n ; ++i){
            ans += primeStr[i];
        }

        return ans;

    }
}

int main(){

    return 0;
}