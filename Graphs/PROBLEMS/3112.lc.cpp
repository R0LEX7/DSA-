#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dijkstra(vector<vector<pair<int , int>>> adj , vector<int>& disappear , int n){
        set<int> vis;
        vector<int> ans(n , 1e8);

        priority_queue <pair<int , int>, vector<pair<int , int>> , greater<pair<int , int>> > pq;

        pq.push({0,0});

        vis.insert(0);

        while(!pq.empty()){
            int node = pq.top().second , dis = pq.top().first ; pq.pop();


            for(auto& p : adj[node]){
                int adjNode = p.first , adjDis = p.second + dis;

                // if(vis.count(adjNode)) continue;
                if(ans[adjNode] <= adjDis )continue;

                if(adjDis < disappear[adjNode]) ans[adjNode] = adjDis;

                pq.push({adjDis , adjNode});
            }

        }

        // for(int i = 0 ; i < n ; ++i){
        //     if(ans[i] != 1e8) continue;
        //     ans[i] = -1;
        // }

        return ans;

    };
    public:
        vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
            vector<vector<pair<int , int>>> adj(n);

            for(auto &edge : edges ){
                int u = edge[0] , v = edge[1] , d = edge[2];

                adj[u].push_back({v , d});
                adj[v].push_back({u , d});
            }


            return dijkstra(adj , disappear , n);

        }
    };


int main(){

    return 0;
}