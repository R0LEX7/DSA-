#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
    int dijkstra(vector<vector<int>>& grid , int n , int m , int k){
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

        queue<vector<int>> q;

        q.push({0,0,0,k});


        while(!q.empty()){
            auto curr = q.front() ; q.pop();
            int x = curr[0] , y = curr[1] ;

            if(x == n-1 && y == m-1) return curr[2];

            vector<pair<int , int>> dxdy = {{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};

            for( auto& dir : dxdy){
                int a = x + dir.first , b = y + dir.second;

                if(a < 0 || b < 0 || a >= n || b >= m ) continue;

                int rem = (grid[a][b] == 1 && curr[3] > 0 ) ? curr[3] -1 : curr[3];

                if( rem < 0 || vis[a][b][rem]) continue;


                vis[a][b][rem] = 1;

                q.push({a , b , curr[2] +1 , rem});
            }

        }
        return -1;
    }
 /*-------------------------------------------------------------*/
    public:
        int shortestPath(vector<vector<int>>& grid, int k) {
            int n = grid.size() , m = grid[0].size();

            return dijkstra( grid , n , m , k);
        }
    };


int main(){

    return 0;
}
