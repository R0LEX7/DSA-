#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
    vector<int> parent , size;

    public:

    DisjointSet(int n){
        size.resize(n+1 , 1);
        parent.resize(n+1);
        for(int i = 1 ; i < n ; ++i) parent[i] = i;
    }

    int findUltimateParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findUltimateParent(parent[u]);
    }

    bool unionOfNodes(int u , int v){
        int U = findUltimateParent(u) , V = findUltimateParent(v);

        if(U == V) return false;

        if(size[U] < size[V]){
            size[V] += size[U];
            parent[U] = V;
        }else{
            size[U] += size[V];
            parent[V] = U;
        }

        return true;
    }
};

class Solution {
    public:
        int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

            DisjointSet aliceDs(n);
            DisjointSet bobDs(n);

            int aliceEdges = 0 , bobEdges = 0 , remainingEdges = 0;

            for(auto& edge : edges){
                int type = edge[0] , u = edge[1] , v = edge[2];

                if(type != 3) continue;

                if(aliceDs.unionOfNodes(u , v) && bobDs.unionOfNodes(u,v)){
                    aliceEdges++;
                    bobEdges++;
                }else remainingEdges++;
            }

            for(auto& edge : edges){
                int type = edge[0] , u = edge[1] , v = edge[2];

                if(type == 3) continue;

                if(type == 1){
                    if(aliceDs.unionOfNodes(u,v)){
                        aliceEdges++;
                    }else remainingEdges++;
                }

                if(type == 2){
                    if(bobDs.unionOfNodes(u,v)){
                        bobEdges++;
                    }else remainingEdges++;
                }
            }

            return (aliceEdges == n-1 && bobEdges == n-1) ? remainingEdges : -1;


        }
    };

int main(){



    return 0;
}