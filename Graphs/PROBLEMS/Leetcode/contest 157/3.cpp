#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n+1);

        for(auto& it: edges){
            int u = it[0] , v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        int par = -1 , d = 0;

        q.push(1);

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int node = q.front(); q.pop();
                d++;

                for(int child : adj[node]){
                    if(par == child) continue;

                    q.push(child);
                }

                par = node;
            }

            return (pow(2 , d-1))%(1e9 + 7);
        }

    }
};©leetcode

int main(){

    return 0;
}