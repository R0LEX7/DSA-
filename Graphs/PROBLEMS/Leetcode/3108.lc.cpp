#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<pair<int , int>>> getAdjacent(vector<vector<int>>& edges , int n) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back({edge[1] , edge[2]});
            adj[edge[1]].push_back({edge[0] , edge[2]});
        }
        return adj;
    }

    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis, int comp,
             unordered_map<int, int>& nodeToComponent, int& andVal) {

        vis[node] = 1;
        nodeToComponent[node] = comp;

        for(auto& [child, wt] : adj[node]) {
            andVal &= wt;
            if (!vis[child]) {
                dfs(child, adj, vis, comp, nodeToComponent, andVal);
            }
        }
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        auto adj = getAdjacent(edges , n);

        vector<int> vis(n, 0), componentAnd(n, ~0), ans;
        unordered_map<int, int> nodeToComponent;
        int comp = 0;

        for(int i = 0 ; i < n ; ++i){
            if (!vis[i]) {
                int andVal = ~0;
                dfs(i, adj, vis, comp, nodeToComponent, andVal);
                componentAnd[comp] = andVal;
                comp++;
            }
        }

        for(auto& q : query){
            int u = q[0], v = q[1];
            if (nodeToComponent.count(u) == 0 || nodeToComponent.count(v) == 0 ||
                nodeToComponent[u] != nodeToComponent[v]) {
                ans.push_back(-1);
            } else {
                ans.push_back(componentAnd[nodeToComponent[u]]);
            }
        }

        return ans;
    }
};



int main(){

    return 0;
}