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
        int largestIsland(vector<vector<int>>& grid) {
            int n = grid.size() , maxi = INT_MIN;

            DisjointSet ds(n*n);



            vector<pair<int,int>> dir = {{1,0} , {-1,0} , {0,1} , {0 , -1}};

            for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    if(!grid[i][j]) continue;
                    for(int k = 0 ; k < 4 ; ++k){
                        int x = dir[k].first + i , y = dir[k].second + j;

                        if (x < 0 || x >= n || y < 0 || y >= n || !grid[x][y]) continue;
                        int u = i*n + j , v = x*n + y;
                        ds.UnionBySize(u , v);
                    }

                }
            }

            for(int i = 0 ; i < n ; ++i){

                for(int j = 0 ; j < n ; ++j){
                set<int> components;

                    if(grid[i][j]) continue;

                    for(int k = 0 ; k < 4 ; ++k){
                        int x = dir[k].first + i , y = dir[k].second + j;
                        if (x < 0 || x >= n || y < 0 || y >= n || !grid[x][y]) continue;
                        int  v = x*n + y;
                        components.insert(ds.FindUltimateParent(v));
                    }
                int totalSize = 0 ;
                for(auto it: components){
                    totalSize += ds.getSize(it);
                }

                maxi = max(maxi , totalSize+1);
                }


            }

            for(int i=0 ; i< n*n ; ++i){
                maxi = max(maxi , ds.getSize(ds.FindUltimateParent(i)));
            }

            return maxi;

        }
    }

int main(){

    return 0;
}
