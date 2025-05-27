#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
    vector<int> parent , size ;

    public:
    DisjointSet(int n){
    parent.resize(n+1);
    size.resize(n+1);

        for(int i = 0 ; i <= n ; ++i){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int a){
        if(a == parent[a]) return a;
        return parent[a] = findParent(parent[a]);
    };

    void unionBySize(int a , int b){
        int U = findParent(a) , V = findParent(b);

        if(U == V) return;

        if(size[U] < size[V]){
            parent[U] = V;
            size[V] += size[U];
        }else {
            parent[V] = U;
            size[U] += V;
        }
    }
};

class Solution {
public:
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> ans;
    DisjointSet ds(n + 1);

   for(auto& it : edges){
    int u = it[0] , v = it[1];
    if(ds.findParent(u) == ds.findParent(v)){
        ans = it;
        continue;
    }

    ds.unionBySize(u , v);
   }

   return ans;
}
};
int main(){

    return 0;
}