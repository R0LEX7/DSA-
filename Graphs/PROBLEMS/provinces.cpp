/**
 * Number of Provinces
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {

    public:
    int provinces = 0;
    vector <int> vis;
    vector<vector<int>> adj ;

    void dfs(int node){

        vis[node] = 1;

        for(int i : adj[node]){
            if(vis[i] ) continue;
            dfs(i);
        }
    }

      int numProvinces(vector<vector<int>> adjacent, int V) {
         vis.assign(V+1 ,0);
        adj.resize(V+1);

         for(int i = 1 ; i <= V ; ++i){
            for(int j = 1 ; j <= V ; ++j){
                if(i-1 == j-1) continue;
                if(adjacent[i-1][j-1]){
                    adj[i].push_back(j);
                }
            }
         }

         for(int i = 1 ; i <= V  ; ++i){
            if(vis[i] ) continue;

            provinces++;
            dfs(i);
         }
         return provinces;
      }
  };


int main(){

    return 0;
}