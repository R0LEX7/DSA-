#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
      // Function to find distance of nearest 1 in the grid for each cell.
      vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int a = 1;
       int n = grid.size() , m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));

        vector<vector<int>> dist(n , vector<int>(m , -1));

        queue <pair<pair<int , int> , int>> q;

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j] != a) continue;
                 q.push({{i , j}, 0});
                 vis[i][j] = 1;

            }
        }

        while(!q.empty()){
            int i = q.front().first.first , j = q.front().first.second , d = q.front().second;

            q.pop();


            dist[i][j] = d;

            int dx[] = {1, -1 , 0 , 0};
            int dy[] = {0 , 0 ,1, -1 };

            for( int k = 0 ; k < 4 ; ++k){
                int x = i + dx[k] , y = j + dy[k];
                if((x >= 0 && x < n) && (y >= 0 && y < m) && !vis[x][y]){
                   q.push({{x, y} , d+1});
                   vis[x][y] = 1;

                }
            }
        }

        return dist;

      }
    };

int main(){

    Solution sol;

    vector<vector<int>> grid = {{0,1,1,0} , {1,1,0,0} , {0,0,1,1}};
    vector<vector<int>> ans = sol.nearest(grid);

    for(auto& arr : ans){
        for( int x : arr){
            cout<<x;
        }
        cout<<endl;
    }

    return 0;
}