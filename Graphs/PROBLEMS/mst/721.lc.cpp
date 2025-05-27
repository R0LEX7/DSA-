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
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
            int n = accounts.size();

            unordered_map<string , int> edges;
            DisjointSet ds(n);

            for(int i = 0 ; i < accounts.size() ; ++i){
                for(int j = 1 ; j < accounts[i].size() ; ++j){
                    string curr = accounts[i][j];
                   if(edges.find(curr) == edges.end()){
                    edges[curr] = i;
                   }else {
                    ds.UnionBySize(edges[curr] , i);
                   }
                }
            }

            vector<vector<string>> ans , mergedMail(n);

            for(auto& it : edges){
                string mail = it.first ; int node = it.second;

                int mainParent = ds.FindUltimateParent(node);

                mergedMail[mainParent].push_back(mail);
            }

            for(int i = 0 ; i < n ; ++i){
                if(mergedMail[i].size() == 0) continue;
              vector<string> temp;
              temp.push_back(accounts[i][0]);
              sort(begin(mergedMail[i]) , end(mergedMail[i]));
              for(string s : mergedMail[i]) temp.push_back(s);

              ans.push_back(temp);
            }

            return ans;

        }
    };


int main(){

    return 0;
}
