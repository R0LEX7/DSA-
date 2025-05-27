#include <bits/stdc++.h>
using namespace std;

class Solution {
    private :
     void dfs(vector<vector<int>>& grid , vector<vector<int>>& vis , int i , int j , int &perimeter , int n , int m){

        if(vis[i][j]) return;

        // mark as visited
        vis[i][j] = 1;




        vector<pair<int , int>> dir = {{0,1} , {1,0} , {-1 , 0} , {0 , -1}};

        // perimeter

        for(int k = 0 ; k < 4 ; ++k){
            int x = dir[k].first + i , y = dir[k].second + j;

            if(x < 0 || x >= n || y < 0 || y >= m || !grid[x][y]) {
                perimeter++;
                continue;

            }

            dfs(grid , vis , x , y , perimeter , n , m);

        }
     };
    public:
        int islandPerimeter(vector<vector<int>>& grid) {
            int n = grid.size() , m = grid[0].size() , perimeter;
            vector<vector<int>> vis(n , vector<int>(m , 0));


            for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < m ; ++j){

                    if(!grid[i][j]) continue;
                    dfs(grid , vis , i , j , perimeter , n , m );
                    break;
                }
            }

            return perimeter;
        }
    };


    int main(){

        return 0;
    }