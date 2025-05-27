#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size() , maxi = INT_MIN;

        queue<pair<int , int>> q;
        vector<vector<int>> dist(n , vector<int>(n , 1e9));

        int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1){
                    q.push({i , j});
                    dist[i][j] = 0;
                }
            }
        }


        while(!q.empty()){

            auto [i , j] = q.front(); q.pop();

            for(auto& [dx , dy] : dir){
                int x = i + dx , y = j + dy;

                if(x < 0 || y < 0 || x >= n || y >= n || dist[x][y] <= dist[i][j] + 1) continue;

                dist[x][y] = dist[i][j] + 1;
                q.push({x,y});

            }
        }

         for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1) continue;

                maxi = max(maxi , dist[i][j]);
            }
        }

       return maxi == 1e9 ? -1 : maxi;

    }
};

int main(){

    return 0;
}