#include <bits/stdc++.h>
using namespace std;


class Solution {
private :
    bool dfs(vector<vector<int>> &adj , int s , int target ,vector<int> & vis){
        if(vis[s]) return ;

        vis[s] = 1;
        for( auto& n : adj[s]){
            if( n == target) return true;

            if (dfs(adj , n , target , vis)) return true;
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;

        vector<vector<int>> adj(n);
        vector<int> vis(n , 0);

        for( auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i = 0 ; i < n ; ++i){
            if (dfs(adj , source , destination , vis) ) return true;
        }

        return false;
    }
};


int main(){

    return 0;
}