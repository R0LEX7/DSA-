#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

    bool bfs(vector<vector<int>>& adj , int a , vector <int> &vis){
        queue<pair<int , int>> q;


        q.push({a , -1});
        vis[a] = 1;

        while(!q.empty()){

            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for( int n : adj[node]){
                if( parent == n) continue;
                if(vis[n]) return true;

                vis[n] = 1;

                q.push({n , node});

            }
        }

        return false;
    }


      // Function to detect cycle in an undirected graph.
      bool isCycle(vector<vector<int>>& adj) {

        vector <int> vis(adj.size()  , 0);
        for(int i = 0 ; i < adj.size() ; i++){
            if(vis[i]) continue;

            if(bfs(adj , i , vis)) return true;
        }

        return false;

      }
  };


int main(){

    return 0;
}