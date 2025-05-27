#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    private :
    vector<int> parent , rank , size;

    public:

    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1 , 0);
        size.resize(n+1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }

    }

    int findUltimateParent(int a){
        if(parent[a] == a) return a;
        return parent[a] = findUltimateParent(parent[a]);
    }

    void unionByRank (int u , int v){
        int ulpU = parent[u] , ulpV = parent[v];

        if(ulpU < ulpV){
            parent[ulpU] = ulpV;
        }else if(ulpV < ulpU){
            parent[ulpV] = ulpU;
        }else {
            parent[ulpV] = ulpU;
            rank[ulpU]++;
        }
    }

    void unionBySize(int u , int v){
        int ulpU = parent[u] , ulpV = parent[v];
        if(ulpU == ulpV) return;

        if(size[ulpU] < size[ulpV]){
            parent[ulpU] = ulpV;
            size[ulpV] += size[ulpU];
        }else {
            parent[ulpV] = ulpU;
            size[ulpU] += size[ulpV];
        }

    }
};

class Solution {
    public:
      // Function to find sum of weights of edges of the Minimum Spanning Tree.
      int spanningTree(int V, vector<vector<int>> adj[]) {
          // code here
          vector<pair<int , pair<int , int>>> edges;
           for (int i = 0 ; i < V ; ++i){
            for(auto& arr : adj[i]){
                int wt = arr[1] , node = i , adjNode = arr[0];
                edges.push_back({wt , { node , adjNode}});
            }
           }

           sort(begin(edges) , end(edges));

           DisjointSet ds(V);

           int mst = 0 ;

           for(auto& edge : edges){
            int wt = edge.first , u = edge.second.first , v = edge.second.second;
            if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                mst += wt;
                ds.unionBySize(u , v);
            }
           }
           return mst;
      }

  };


int main(){



    return 0;
}