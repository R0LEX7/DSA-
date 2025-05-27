#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

    // solving using dfs approach
    bool dfs(vector<vector<int>>& adj , int s , vector <int> &vis , int parent){
        if(vis[s]) return true;

        vis[s] = 1;

        for(int n : adj[s]){
            if(parent == n) continue;

            if(dfs(adj , n , vis , s)) return true;
        }

       return false;
    }


      // Function to detect cycle in an undirected graph.
      bool isCycle(vector<vector<int>>& adj) {

        vector <int> vis(adj.size()  , 0);
        for(int i = 0 ; i < adj.size() ; i++){
            if(vis[i]) continue;
            if(dfs(adj , i , vis , -1)) return true;
        }

        return false;

      }
  };


int main(){

    return 0;
}