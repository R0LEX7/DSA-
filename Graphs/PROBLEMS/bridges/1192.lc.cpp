#include <bits/stdc++.h>
using namespace std;


class Solution {
    private :
    int cnt = 1;

    void dfs(int node , int  parent , vector<vector<int>>& adj , vector<vector<int>>& bridges , vector<int>& vis , vector<int>& low , vector<int>& time){
        vis[node] = 1;
        low[node] = time[node] = cnt++;

        //  traversing through adj

        for(int n : adj[node]){
            if(n == parent ) continue;

            if(!vis[n]){
                dfs(n , node , adj , bridges , vis , low , time);

                low[node] = min(low[node] , low[n]);
                if(low[n] > time[node]){
                    bridges.push_back({node , n});
                }
            }else low[node] = min(low[node] , time[n]);
        }
    }
    public:
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            vector<vector<int>> adj(n) , bridges;

            for( auto& arr : connections){
                adj[arr[0]].push_back(arr[1]);
                adj[arr[1]].push_back(arr[0]);
            }

            vector<int> vis(n,0) , low(n) , time(n);

            dfs(0 , -1 , adj , bridges , vis , low , time);
            return bridges;


        }
    };


int main(){

    return 0;
}
