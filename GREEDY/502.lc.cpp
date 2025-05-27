#include <bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size() , net = 0;

        vector<pair<int , int>> vp;

        priority_queue<int> pq;


        for(int i = 0 ; i < n ; i++) vp.push_back({capital[i] , profits[i]});

        sort(vp.begin() , vp.end());

        int ind = 0;
        for(int i = 0 ; i < k ; i++){

            while(vp[ind].first <= w) pq.push(vp[ind].second);

            if(pq.empty()) break;

            w += pq.top();
            pq.pop();

        }

        return w;
    }


int main(){

    return 0;
}