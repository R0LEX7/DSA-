#include <bits/stdc++.h>
using namespace std;

    int minOperations(vector<int>& arr, int k) {
        int n = arr.size();
        int op = 0;

       priority_queue<long long, vector<long long>, greater<int>> pq;

       for( long long x : arr){
        pq.push(x);
       }

       while(pq.top() < k){
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();


        long  long val = min(x , y) *2 + max(x,y);
        pq.push(val);
        op++;
       }

        return op;
    }


int main(){

    return 0;
}