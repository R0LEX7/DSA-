#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
    vector<vector<int>> grid , vis ;
    int n ,  m ;

    int dir[4][2] = {{1,0} , {0,1} , {-1, 0} , {0 , -1}};

    void bfs(int i , int j , pair<int , int>& last){

        queue<pair<int , int>> q;

        q.push({i , j});

        vis[i][j] = 1;

        while(!q.empty()){

            int sz = q.size();

            while(sz--){
                auto [a , b] = q.front(); q.pop();

                last = {a , b};

                for(auto& [dx , dy] : dir){
                    int x = a+dx , y = b+dy;

                    if(x <0 || y<0 ||x >= n || y >= m ||vis[x][y] || grid[x][y] == 0) continue;
                    vis[x][y] = 1;
                    q.push({x,y});
                }
            }
        }
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        this->n = land.size() , this->m = land[0].size();
        this->grid = land;

        vis.resize(n , vector<int>(m , 0));

        vector<vector<int>> ans;

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0; j < m ; ++j){

                if(land[i][j] == 0 || vis[i][j]) continue;

                pair<int , int> last = {};

                bfs(i , j , last);

                ans.push_back({i , j , last.first , last.second});
            }
        }

        return ans;

    }
};

int main(){

    return 0;
}