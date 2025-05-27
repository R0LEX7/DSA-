#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
    int dijkstra(vector<vector<int>>& grid , int n , int m){

        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq;
        vector<vector<int>> dis(n , vector<int>(m , 1e8));

        pq.push({0,{0,0}});
        //{dis , {x , y}}

        vector<pair<int , int>> dxdy = {{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};

        while (!pq.empty()){
            auto [d , p] = pq.top(); pq.pop();
            auto [x , y] = p;

            for(int k = 0 ; k < 4 ; ++k){
                int a = x + dxdy[k].first , b = y + dxdy[k].second;

                if(a < 0 || b < 0 || a >= n || b >= m) continue;

                int wt = grid[a][b] == 0 ? 0 : 1;

                if(d + wt < dis[a][b]){
                    dis[a][b] = d+wt;
                    pq.push({d + wt , {a , b}});
                }


            }

        }
        return dis[n-1][m-1];

    }
    public:
        int minimumObstacles(vector<vector<int>>& grid) {

            int n = grid.size() , m = grid[0].size();

            return dijkstra( grid , n , m);
        }
    };


int main(){

    Solution sol;

    vector<vector<int>> grid = {{0,1,0,0,0} ,{0,1,0,1,0} , {0,0,0,1,0}};

    auto ans = sol.minimumObstacles(grid);

    cout<<ans ;



    return 0;
}