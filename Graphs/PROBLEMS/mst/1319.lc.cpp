#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
    vector<int> parent , size ;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int v = 0 ; v < n ; v++){
            parent[v] = v;
            size[v] = 1;
        }
    }

    int FindUltimateParent (int u){
        if( parent[u] == u) return u;
        return parent[u] = FindUltimateParent(parent[u]);
    }

    void UnionBySize (int u , int v){
        int U = FindUltimateParent(u) , V = FindUltimateParent(v);
        if(U== V) return;

        if(size[U] < size[V]){
            parent[U] = V;
            size[V] += size[U];
        }else{
            parent[V] = U;
            size[U] += size[V];
        }
    }
};

class Solution {
    public:
        int makeConnected(int n, vector<vector<int>>& connections) {
            int extraEdges = 0;

            DisjointSet ds(n);

            for(auto& arr : connections){
                int u = arr[0] , v = arr[1];
                if(ds.FindUltimateParent(u) == ds.FindUltimateParent(v)) extraEdges++;
                ds.UnionBySize(u , v);
            }
            int nc = 0;
            for(int i = 0 ; i < n ; ++i){
                if(ds.FindUltimateParent(i) == i) nc++;
            }

            if(extraEdges < nc-1) return -1;
            return nc-1;
        }
    };


int main(){

    return 0;
}