#include <bits/stdc++.h>
using namespace std;


class DisjointSet {

    public:
    vector<int> parent , size ;
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

    int getSize(int u){
        return size[u];
    }
};

class Solution {
    public:
        int removeStones(vector<vector<int>>& stones) {
            int n = stones.size();
            DisjointSet ds(n*n);

            set<int> myset;
            for(auto& arr : stones){

                int x = arr[0] , y = arr[1] , u = x*n + y;

                // rows
                for(int k = 0 ; k < n ; ++k){
                    int v = x*n + k;
                   ds.UnionBySize(u,v);
                }
                // col
                for(int k = 0 ; k < n ; ++k){
                    int v = k*n + y;
                   ds.UnionBySize(u,v);
                }
                myset.insert(ds.FindUltimateParent(u));
            }

            return n - myset.size();
        }
    };
int main(){

    return 0;
}
