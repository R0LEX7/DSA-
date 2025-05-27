#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

            vector<int> ind(n , 0);
            vector<int> res;

            int nodes = n;

            vector<vector<int>> adj(n);

            set<pair<int, int>> seen;

            for (auto& edge : edges) {
                int u = edge[0], v = edge[1];
                if (u > v) swap(u, v);  // Always store smaller first to avoid duplicates

                if (seen.count({u, v})) continue;
                seen.insert({u, v});

                ind[u]++;
                ind[v]++;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            queue<int> q;

            for(int i = 0 ; i < n ; ++i){
                if(ind[i] != 1) continue;
                q.push(i);
            }

            while(nodes > 2){

                int qSize = q.size();
                nodes -= qSize;

                while(qSize){
                    int node = q.front(); q.pop();

                    for(int adjNode : adj[node]){
                        ind[adjNode]--;

                        if(ind[adjNode] == 1){
                            q.push(adjNode);
                        }
                    }
                    qSize--;
                }
            }

            while(!q.empty()){
                int node = q.front(); q.pop();
                res.push_back(node);
            }

            if(res.size() == 0){
                res.push_back(0);
            }

            return res;
        }
    };


int main(){

    Solution sol;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {0, 3},
        {0, 4},
        {0, 5},
        {0, 6},
        {1, 7},
        {1, 8},
        {1, 9}
    };

    vector <int> ans = sol.findMinHeightTrees(10 , edges);

    for(int x : ans) cout<<x<<" "<<endl;

    return 0;
}