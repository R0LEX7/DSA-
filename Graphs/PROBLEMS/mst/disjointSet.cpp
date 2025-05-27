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

    int findUnion(int a){
        if(parent[a] == a) return a;
        return parent[a] = findUnion(parent[a]);
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


int main(){

    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    ds.unionBySize(3, 7);

if(ds.findUnion(3) == ds.findUnion(7)){
cout<<"same\n"<<endl;
}else cout<<"not same\n";


    return 0;
}