#include <bits/stdc++.h>
using namespace std;


class Solution {
    private :
    int shortestDistance( vector<vector<int>> &adj){
        int n = adj.size();

        queue<pair<int ,int>> q; q.push({0 , 0});

        while(!q.empty()){
            int node = q.front().first , d = q.front().second; q.pop();

            if(node == n-1) return d;;

            for(int adjNode : adj[node]){
                q.push({adjNode , d+1});
            }
        }

        return -1;

    }
    public:
        vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
            vector<vector<int>> adj(n) ; vector<int> res(queries.size());

            for(int i = 0 ; i < n-1; ++i){
                adj[i].push_back(i+1);
            }

            int dist = n-1;

            for(auto& edge : queries){
                adj[edge[0]].push_back(edge[1]);

                dist = min(dist , shortestDistance(adj));
                res.push_back(dist);
            }

            return res;

        }
    };

int main(){

    return 0;
}