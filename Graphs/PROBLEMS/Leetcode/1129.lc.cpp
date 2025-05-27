#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        vector<vector<pair<int , int>>> adj(n);

        for(auto& it : redEdges){
            int u = it[0] , v = it[1] , col = 1;

            adj[u].push_back({v , col});
        }

        for(auto& it : blueEdges){
            int u = it[0] , v = it[1] , col = 0;

            adj[u].push_back({v , col});
        }

        vector<int>  dist(n , 1e8);

        queue<tuple<int ,  int , int>> q;
        vector<vector<int>> vis(n, vector<int>(2, 0));
        vis[0][1] = 1 ; vis[0][0] = 1;


        q.push({0 ,0 , -1});
            dist[0] = 0;
        //{node , dis , colour }

        while(!q.empty()){

            auto [ node ,step ,  col] = q.front() ; q.pop();

            int nextCol = col == 1 ? 0 : 1;


            for(auto& [ child , childCol] : adj[node]){
                    if(vis[node][nextCol] || nextCol == col || dist[child] <= dist[node] + 1) continue;
                    dist[child] = dist[node] + 1;
                    q.push({child , dist[child] , nextCol});
                    vis[child][nextCol] = 1;
                }
            }




        for(auto& a : dist){
            if(a == 1e8) a = -1;
        }

        return dist;

    }
};

int main(){

    return 0;
}