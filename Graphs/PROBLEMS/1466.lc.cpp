#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minReorder(int n, vector<vector<int>>& connections) {
        set <pair<int , int>> edges ;
        vector<vector<int>> adj(n);

        vector<int> vis(n , 0);

        for( auto& e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            edges.insert({e[0] , e[1]});
        }

        int ans = 0;

        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while(!q.empty()){
            int parent = q.front(); q.pop();

            for( int node : adj[parent]){
                if(vis[node]) continue;

                if(edges.count({parent , node})) ans++;

                vis[node] = 1;

                q.push(node);
            }
        }
        return ans;
        }
    };

int main(){

    Solution sol ;
    int n = 5;
vector<vector<int>> connections = {
    {1, 0},
    {1, 2},
    {3, 2},
    {3, 4}
};

cout<<sol.minReorder(n , connections)<<endl;

    return 0;
}