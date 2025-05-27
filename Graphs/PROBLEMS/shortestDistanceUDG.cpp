#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to find the shortest path from source to all other nodes
      vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dis(n, 1e9);

        queue<pair<int,int>> q;
        dis[src] = 0;
        q.push({src , 0});

        while(!q.empty()){
            int node = q.front().first , d = q.front().second;
            q.pop();

            for(int a : adj[node]){
                if(dis[a] < d + 1) continue;

                dis[a] = d+1;
                q.push({a,d+1});
            }

        }

        return dis;

      }
  };


int main(){

    vector<vector<int>> adj = {
        {1, 3},       // Node 0 is connected to nodes 1 and 3
        {0, 2},       // Node 1 is connected to nodes 0 and 2
        {1, 6},       // Node 2 is connected to nodes 1 and 6
        {0, 4},       // Node 3 is connected to nodes 0 and 4
        {3, 5},       // Node 4 is connected to nodes 3 and 5
        {4, 6},       // Node 5 is connected to nodes 4 and 6
        {2, 5, 7, 8}, // Node 6 is connected to nodes 2, 5, 7, and 8
        {6, 8},       // Node 7 is connected to nodes 6 and 8
        {7, 6}        // Node 8 is connected to nodes 7 and 6
    };
    Solution sol;
    vector<int> ans = sol.shortestPath(adj , 0);

    for(int x : ans){
        cout<<x<<endl;
    }

    return 0;
}
