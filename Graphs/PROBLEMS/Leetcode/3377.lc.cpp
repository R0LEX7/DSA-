#include <bits/stdc++.h>
using namespace std;


class Solution {
private :
    bool isPrime(int n){
        if(n<2) return 0;

        for(int i = 2 ; i*i <=n ; ++i){
            if(n%i == 0) return 0;
        }

        return 1;
    }

    vector<int> getDigits(int num) {
        vector<int> digits;
        if (num == 0) {
            digits.push_back(0);
            return digits;
        }
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }

    int digitsToNum(const vector<int>& digits) {
        int num = 0;
        for (int d : digits) {
            num = num * 10 + d;
        }
        return num;
    }

public:
    int minOperations(int n, int m) {
        if(isPrime(n) || isPrime(m)) return -1;

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int,int>>> pq;

        unordered_set <int> vis;

        pq.push({n , n});
        // {cost , num}
        vis.emplace(n);

        while(!pq.empty()){

            auto [currCost , currNum] = pq.top() ; pq.pop();

            if(currNum == m) return currCost;

            vector<int> digits = getDigits(currNum);

           for (int i = 0; i < digits.size(); ++i) {
                int d = digits[i];
                // agar d < 9 hai toh increase krskte hai

                if(d<9){
                    vector<int> newDigits = getDigits(currNum);

                    newDigits[i]++;

                    int newNum = digitsToNum(newDigits);

                    if(isPrime(newNum) || vis.count(newNum)) continue;

                    vis.emplace(newNum);
                    pq.push({currCost + newNum , newNum});
                }

                // agar d > 0 hai toh decrease krskte hai

                if(d>0){
                    vector<int> newDigits = getDigits(currNum);

                    newDigits[i]--;

                    int newNum = digitsToNum(newDigits);

                    if(isPrime(newNum) || vis.count(newNum)) continue;

                    vis.emplace(newNum);
                    pq.push({currCost + newNum , newNum});
                }
            }


        }

        return -1;


    }
};

int main(){

    return 0;
}
