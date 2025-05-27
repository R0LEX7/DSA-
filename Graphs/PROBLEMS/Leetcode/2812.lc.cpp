#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size() , e = 1e8;

        if(grid[0][0 == 1 || grid[n-1][n-1]] == 1) return 0;

        vector<vector<int>> dist(n , vector<int>(n , e));

        queue<pair<int , int>> q;


        // sare thieves ko queue me dalo and sare cells se thieves ki distance nikalo bfs se
        for(int i = 0 ; i <n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dir[4][2] = {{1,0} , {0,1},{0,-1},{-1,0}};


        while(!q.empty()){
            auto [i , j] = q.front() ; q.pop();


            for(auto& [a , b] : dir){

                int x = i +a , y = j + b;

                if(x< 0 || y<0 || x>= n || y >=n || dist[x][y] <= dist[i][j] +1) continue;

                dist[x][y] = dist[i][j] +1;

                q.push({x,y});
            }

            // max heap

            priority_queue<pair<int , pair<int , int>>> pq;

            pq.push({dist[0][0] , {0,0}});

            vector<vector<int>> vis(n , vector<int>(n , 0));

            vis[0][0] = 1;

            while(!pq.empty()){

                auto [currSafety , pos] = pq.top() ; pq.pop();

                auto [i , j] = pos;

                if(i == n-1 && j == n-1) return currSafety;

                for(auto& [a , b] : dir){

                int x = i +a , y = j + b;

                if(x< 0 || y<0 || x>= n || y >=n || vis[x][y]) continue;

               int minDist = min(currSafety , dist[x][y]);

               vis[x][y] = 1;

                pq.push({minDist ,{x,y}});
            }
            }
        }

        return 0;


    }
};

int main(){

    return 0;
}
