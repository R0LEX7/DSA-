#include <bits/stdc++.h>
using namespace std;


class Solution {
private :

    vector<vector<int>> getAdjacent(vector<vector<int>>& edges){
        int n = edges.size();

        vector<vector<int>> adj(n);

        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return adj;
    };

    void dfs(int node , int parent , int dis , vector<vector<int>>& adj , pair<int , int>& p){

        if(dis > p.first){
            p = {dis , node};
        }

        for(int child : adj[node]){
            if(child == parent) continue;

            dfs(child , node , dis+1 , adj , p);
        }
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        auto adj1 = getAdjacent(edges1) , adj2 = getAdjacent(edges2);

        pair<int , int> res1 = {INT_MIN , -1} , res2 = {INT_MIN , -1};


        // traverse through extreme end nodes
        dfs(0 , -1 , 0 , adj1 , res1);
        dfs(res1.second , -1 , 0 , adj1 , res2);

        int d1 = res2.first;

        res1 = {INT_MIN , -1} ; res2 = {INT_MIN , -1};

        // traverse through extreme end nodes
        dfs(0 , -1 , 0 , adj2 , res1);
        dfs(res1.second , -1 , 0 , adj2 , res2);

        int d2 = res2.first;

        return max(d1 , d2 , (ceil(d1/2) + ceil(d2/2) + 1));


    }
};

int main(){

    return 0;
}