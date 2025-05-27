#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

vector<int> dijkstra(vector<vector<pair<int , int>>>& adj , int src){
    int n = adj.size();

    vector<int> dis(n , 1e8);

    priority_queue<pair<int , int> , vector<pair<int , int>>, greater<pair<int , int>>> pq;

    pq.push({0 , src});

    dis[src] = 0;

    while(!pq.empty()){
        auto [d , node] = pq.top() ; pq.pop();

        for(auto& p: adj[node]){
            auto&[child , childDis] = p;

            if(childDis + d < dis[child]){
                dis[child] = childDis + d;

                pq.push({ d+childDis , child});
            }
        }
    }

    return dis;
}

vector<vector<pair<int , int>>> getAdjacent(vector<vector<int>>& edges , int n) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back({edge[1] , edge[2]});
            adj[edge[1]].push_back({edge[0] , edge[2]});
        }
        return adj;
    };

public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {

        auto adj = getAdjacent(edges , n);

        vector<int> DJS = dijkstra(adj , 0) , DJE = dijkstra(adj , n-1);

        vector<bool> ans;

        int sd = DJS[n-1];

        for(auto& edge : edges){
            int u = edge[0] , v = edge[1] , wt = edge[2];

            bool isEdgeIncluded = (DJS[u] + DJE[v] + wt == sd) || (DJS[v] + DJE[u] + wt) == sd;

            if(isEdgeIncluded) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;

    }
};


int main(){

    return 0;
}