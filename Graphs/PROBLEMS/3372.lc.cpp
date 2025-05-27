#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int bfs (vector<vector<int>> & adj , int k , int s){
        queue<pair <int ,int>> q;

        int n = adj.size();
        q.push({s , 0});
        // {node , dist}

        vector<int> vis(n , 0);
        vis[s] = 1;

        int ans = 1;

        while(!q.empty()){
            int node = q.front().first , d = q.front().second  + 1; q.pop();

            for( int n : adj[node]){
                if(vis[n]) continue;
                if(d <= k) ans++;

                q.push({n , d});
                vis[n] = 1;
            }

        }
        return ans;
    }
    public:
        vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
            int n = edges1.size() + 1 , m = edges2.size() +1 , ans2 = INT_MAX;
            vector<vector<int>> adj1(n) , adj2(m) ;

            vector<int> res(n);

            for(auto& it : edges1){
                adj1[it[0]].push_back(it[1]);
                adj1[it[1]].push_back(it[0]);
            }
            for(auto& it : edges2){
                adj2[it[0]].push_back(it[1]);
                adj2[it[1]].push_back(it[0]);
            }

            for(int i = 0 ; i < m ; ++i){
                ans2 = max(ans2 , bfs(adj2 , k-1 , i));
            }

            for(int i = 0 ; i < n ; ++i){
                res[i] = bfs(adj1 , k , i) + ans2;
            }

            return res;
        }

    };


int main(){

    return 0;
}