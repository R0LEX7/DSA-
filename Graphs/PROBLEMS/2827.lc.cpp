#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    long long dfs(vector<vector<int>>& adj , vector<int>& values , int n , int k , int ans , int src , int parent){
        long long sum = values[src];

        for(int child : adj[src]){
            if(child == parent) continue;

            int childSum = dfs(adj , values , n , k , ans , child , src);

            if(childSum%k == 0) ans++;
            else sum += childSum;
        }
        return sum;
    }
    public:
        int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
            vector<vector<int>> adj(n);

            for(auto& edge : edges ){
                int u = edge[0] , v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            int ans = 0;

            dfs(adj , values , n , k , ans , 0 , -1);

            return ans+1;

        }
    };


int main(){

    return 0;
}