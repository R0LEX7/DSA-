#include <bits/stdc++.h>
using namespace std;




class Solution {
    private:
    int n ;
    vector<int> count , ans;
    vector<vector<int>> adj;

    void dfs(int node , int parent){

        for(int child : adj[node]){
            if(child == parent) continue;

            dfs(child , node);
            count[node] += count[child];
            ans[node] += ans[child] + count[child];
        }
    }


    void dfs2(int node , int parent){

        for(int child : adj[node]){
            if(child == parent) continue;


            ans[child] = ans[node] - count[child] + (n - count[child] );
            dfs2(child , node);
        }
    }


    public:
        vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {

            this->n = N;
            this->adj.resize(n);

            for(auto& edge : edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }

            this->count.resize(n , 1);
            this->ans.resize(n , 0);

            dfs(0 , -1);
            dfs2(0 , -1);

            return ans;


        }
    };

int main(){

    return 0;
}