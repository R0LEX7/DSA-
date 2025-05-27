#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
    vector<int> parent;
    vector<string> strs;

    public:
    DisjointSet(int n , vector<string> strs){

        parent.resize(n);
        this->strs = strs;
        for(int i = 0 ; i < n ; ++i){

            parent[i] = i;
        }
    }

    int findUltimateParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findUltimateParent(parent[u]);
    }

    bool areSimilar(int u, int v) {
        int cnt = 0 , m = strs[u].size();

        for (int i = 0; i < m; ++i) {
            if (strs[u][i] != strs[v][i]) cnt++;
            if (cnt > 2) return false;
        }
        return cnt == 0 || cnt == 2;
    }


    void unionBySize(int u , int v){
        int U = findUltimateParent(u) , V = findUltimateParent(v);

        if(U == V) return;

        if(areSimilar(u , v)){
            int mainParent = min(U , V);
            parent[U] = mainParent;
            parent[V] = mainParent;
        }

    }
};

class Solution {
    public:
        int numSimilarGroups(vector<string>& strs) {
            int n = strs.size();
            DisjointSet ds(n , strs);

            for(int i = 0 ; i < n ; ++i){
                for(int j = i ; j < n ; ++j){
                    if(i == j) continue;
                    ds.unionBySize(i , j);
                }
            }

            set<int> par;

            for(int i = 0 ; i < n ; ++i){
                par.insert(ds.findUltimateParent(i));
                cout<<ds.findUltimateParent(i)<<endl;
            }



            return par.size();

        }
    };


int main(){

    vector<string>  strs = {"tars","tars"};

    Solution sol;

    int ans = sol.numSimilarGroups(strs);

    cout<<"ans is "<< ans<<endl;

    return 0;
}
