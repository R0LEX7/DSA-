#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
    vector<int> parent , size;

    public:

    DisjointSet(int n){
        size.resize(n , 1);
        parent.resize(n);
        for(int i = 0 ; i < n ; ++i) parent[i] = i;
    }

    int findUltimateParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findUltimateParent(parent[u]);
    }

    void unionOfNodes(int u , int v){
        int U = findUltimateParent(u) , V = findUltimateParent(v);

        if(U == V) return;

        if(size[U] < size[V]){
            size[V] += size[U];
            parent[U] = V;
        }else{
            size[U] += size[V];
            parent[V] = U;
        }
    }
};

class Solution {
    private:
    bool compare(vector<int> a , vector<int> b){
        return a[2] < b[2];
    }
    public:
        vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
            int m = queries.size();

            vector<bool> ans(m);
            for(int i = 0 ; i < m ; ++i){
                queries[i].push_back(i);
            }

            sort(edgeList.begin(), edgeList.end() , compare);
            sort(queries.begin(), queries.end() , compare);

            DisjointSet ds(n);

            int ind = 0;

            for(auto& query : queries){
                int limit = query[2] , u = query[0] , v = query[1];

                while( ind < edgeList.size() && edgeList[ind][2] < limit){
                    int x = edgeList[ind][0] , y = edgeList[ind][1];
                    ds.unionOfNodes(x , y);
                    ind++;
                }

                if(ds.findUltimateParent(u) == ds.findUltimateParent(v)) ans[query[3]] = true;
                else ans[query[3]] = false;
            }

            return ans;
        }
    };

int main(){

    return 0;
}