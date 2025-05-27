#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<pair<int , int>>> adj;
    int n , ct , ss ;

    void dfs(int node , int parent , int dis){

        if((dis%ss) == 0) ct++;

        for(auto& [child , d] : adj[node]){

            if(parent == child) continue;

            dfs(child , node , d+dis);
        }
    }



public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        this->n = edges.size() +1 , this->ss = signalSpeed;
        adj.assign(n, {});

        for(auto& it : edges){
            int u = it[0] , v = it[1] , wt = it[2];

            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }

        vector<int> ans(n , 0);

        for(int par = 0 ; par < n ; ++par ){
            int res = 0 , sum = 0;
            vector<int> totalGoodNodes;
            for(auto& [child , d] : adj[par]){
                ct = 0;
                dfs(child , par , d);

                totalGoodNodes.push_back(ct);
                sum += ct;
            }

            for(int e : totalGoodNodes) res += (sum - e)*e;

            ans[par] = res/2;
        }

        return ans;
    }
};

int main(){

    return 0;
}