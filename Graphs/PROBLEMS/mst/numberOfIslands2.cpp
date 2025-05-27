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
      vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {

        DisjointSet ds(n*m);

        vector<vector<int>> vis(n , vector<int>(m , 0));

        int cnt = 0;
        vector<int> ans;

        for(auto& op : operators){
            int x = op[0] , y = op[1];

            if(vis[x][y]) {
                ans.push_back(cnt);
                continue;
            }

            cnt++;

            vector<pair<int,int>> dir = {{1,0} , {-1,0} , {0,1} , {0 , -1}};

            for(int k = 0 ; k < 4 ; ++k){
                int a = dir[k].first , b = dir[k].second;

                if (a < 0 || a >= n || b < 0 || b >= m || !vis[a][b]) continue;
                int u = x*m + y , v = a*m + b;

                if(ds.FindUltimateParent(u) == ds.FindUltimateParent(v)) continue;

                ds.UnionBySize(u , v);
                cnt--;
            }

            ans.push_back(cnt);
        }
        return ans;
      }
  };



int main(){

    return 0;
}
