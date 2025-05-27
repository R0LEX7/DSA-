#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int djisktraAlgo(vector<vector<int>>& grid ,  pair<int, int> &source , pair<int, int> &destination , int factor = 1) {


            int n = grid.size() ,m = grid[0].size() ;
            if(grid[0][0] == !factor || grid[n-1][m-1] == !factor) return -1;


            vector<vector<int>> dis(n , vector<int>(m , 1e9));

            priority_queue<pair<int,pair<int ,int>>, vector<pair<int,pair<int ,int>>>, greater<pair<int,pair<int ,int>>>> pq;
            // distance , {x,y}
            pq.push({1,source});
            dis[source.first][source.second] = 1;

            while(!pq.empty()){
                int d = pq.top().first , x = pq.top().second.first , y = pq.top().second.second;
                pq.pop();

                if(x == destination.first && y == destination.second) return d;

                vector<pair<int,int>> dir = {{0,1} , {1,0} , {0,-1} , {-1,0} , {1,1} , {1,-1} , {-1,1} , {-1,-1}};

                for(auto& cord : dir){
                    int a = x + cord.first , b = y + cord.second;

                    if(a < 0 || a >= n || b < 0 || b >= m || grid[a][b] == !factor) continue;

                    int childDis = d + 1;

                    if(dis[a][b] <= childDis) continue;

                    dis[a][b] = childDis;

                    pq.push({childDis , {a , b}});
                }
            }

            return -1;
        };

        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

            pair<int , int> source = {0,1} , destination = {2,2};

            return djisktraAlgo(grid , source , destination);
        }
    };


int main(){

    vector<vector<int>> grid =  {{1, 1, 1, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 1},
    {1, 1, 0, 0},
    {1, 0, 0, 1}};
    Solution sol;

    cout<<sol.shortestPathBinaryMatrix(grid);

    return 0;
}
