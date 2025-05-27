#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

        // function to do traversal bfs

        void bfs(vector<vector<char>>& grid , pair<int , int> start , int n , int m , vector<vector<int>>& vis){
            if(start.first >= n && start.second >= m && vis[start.first][start.second]) return;

            queue<pair<int , int>> q;
            q.push(start);

            while(!q.empty()){
                pair <int , int> node = q.front();
                q.pop();
                int x = node.first , y = node.second;
                vis[x][y] = 1;

                for(int i = -1 ; i <= 1 ; ++i){
                    for(int j = -1 ; j <= 1 ; ++j){
                        int a = x + i , b = y + j;
                        if(a >= 0 && a < n && b >=0 && b < m &&
                            grid[a][b] == '1' && !vis[a][b]){
                                q.push({a , b});
                                vis[a][b] = 1;
                            }
                    }
                }



            }
        }
      // Function to find the number of islands.
      int numIslands(vector<vector<char>>& grid ) {
            int n = grid.size() , m = grid[0].size() , cnt = 0;
          vector<vector<int>> vis( n+1 , vector<int>(m+1 , 0));

          for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(grid , {i , j} , n , m , vis);
                }
            }
          }
          return cnt;
      }
  };


int main(){

    return 0;
}
