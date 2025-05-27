#include <bits/stdc++.h>
using namespace std;

 int minStoneSum(vector<int>& arr, int k) {
    priority_queue <int> pq;
    int sum = 0;

    for(int n : arr){
        pq.push(n);
        sum += n;
    }

    for(int i = 0 ; i < k ; i++){
        int mx = ceil(pq.top()/2);
        sum -= pq.top() - mx;
        pq.pop();
        pq.push(mx);

    }
        return sum;
    }


int main(){

    return 0;
}
