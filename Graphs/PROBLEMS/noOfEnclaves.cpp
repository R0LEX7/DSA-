#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // using dfs traversal
     void dfs(int i , int j , vector<vector<int>> &vis , vector<vector<int>> grid){
        if(grid[i][j] == 0 && vis[i][j]) return;
        int n = grid.size() , m = grid[0].size();
        vis[i][j] = 1;

        int dx[] = {-1, 1 , 0,0};
        int dy[] = {0,0,-1, 1 };

        for(int k = 0 ; k < 4 ; ++k){
            int x = i + dx[k] ,  y = j + dy[k];

            if((x >= 0 && x < n) && (y >= 0 && y < m) && !vis[x][y]){
                dfs(x,y,vis,grid);
            }
        }
     };
      int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size() , m = grid[0].size() , cnt = 0;
        vector<vector <int>> vis(n , vector<int>(m , 0));

        for(int i = 0 ; i < n ; ++i){
            if(!vis[i][0] && grid[i][0] == 1) dfs(i , 0 , vis , grid);
            if(!vis[i][m-1] && grid[i][m-1] == 1) dfs( i , m-1 , vis , grid);

        }

        for(int j = 0 ; j < m ; ++j){
            if(!vis[0][j] && grid[0][j] == 1) dfs(0 , j , vis , grid);
            if(!vis[n-1][j] && grid[n-1][j] == 1) dfs( n-1 , j , vis , grid);

        }

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(vis[i][j] == 0 && grid[i][j] == 1) cnt++;
            }
        }

        return cnt;
      }
  };


int main(){

    vector<vector<int>> grid{
        {0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}};

    Solution obj;
    cout << obj.numberOfEnclaves(grid) << endl;


    return 0;
}