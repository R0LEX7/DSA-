#include <bits/stdc++.h>
using namespace std;

class Solution {


    public:
      // Function to return a list containing the DFS traversal of the graph.
      vector<int> vis;
      vector <int> dfsList;
        vector<vector<int>> adj;
      void dfs(int node){
        if(vis[node]) return ;

        // mark node as visited ;
        vis[node] = 1;
        dfsList.push_back(node);
        for(auto child : adj[node]){
            dfs(child);
        };

      }
      vector<int> dfsOfGraph(vector<vector<int>>& adjacent) {
        this->adj = adjacent;
        int n = adj.size();
        vis.assign(n+1 , 0);
        dfs(0);
        return dfsList;

      }
    };

int main(){
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    Solution sol;
    vector<int> ans = sol.dfsOfGraph(adj);

    for (int x : ans){
        cout << x << endl;
    }

    return 0;
}