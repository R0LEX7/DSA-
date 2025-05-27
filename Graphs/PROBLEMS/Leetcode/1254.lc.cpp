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

    int n , m ;

    int getPosition( int i , int j  ){
        return i*m + j;
    }

    void markBoundaryConnected(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        // Add all boundary 0s to queue
        for(int i = 0; i < n; ++i) {
            if(grid[i][0] == 0) q.push({i, 0});
            if(grid[i][m-1] == 0) q.push({i, m-1});
        }
        for(int j = 0; j < m; ++j) {
            if(grid[0][j] == 0) q.push({0, j});
            if(grid[n-1][j] == 0) q.push({n-1, j});
        }

        // Mark all boundary-connected 0s
        int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        while(!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            if(grid[i][j] != 0) continue;
            grid[i][j] = -1; // Mark as boundary-connected
            for(auto& [di,dj] : dir) {
                int x = i + di, y = j + dj;
                if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 0) {
                    q.push({x,y});
                }
            }
        }
    }

    void help(int i , int j  , vector<vector<int>> &vis ,  vector<vector<int>>& grid , DisjointSet &ds){

         int dir[4][2] = {{1,0} , {0,1},{0,-1},{-1,0}};

         for(auto& [a , b] : dir){

                int x = i +a , y = j + b;

                if(x< 0 || y<0 || x>= n || y >=m || vis[x][y]  || grid[x][y] != 0) continue;

                ds.unionOfNodes(getPosition(i , j) , getPosition(x , y));

                vis[x][y] = 1;

                help(x , y ,vis , grid , ds);
            }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();

        this->n = n ;
        this->m = m;

        DisjointSet ds(n*m +1);



        markBoundaryConnected(grid);

        vector<vector<int>> vis(n , vector<int>(m , 0));

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j] == 0 &&  vis[i][j] == 0){
                    help(i , j , vis , grid , ds);
                }
        }
    }

    unordered_set <int> parents;

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j] != 0 ) continue;

                int mainParent = ds.findUltimateParent(getPosition(i , j));

                if(parents.count(mainParent)) continue;

                parents.emplace(mainParent);

        }
    }

    return parents.size();


}
};


int main(){

    return 0;
}
