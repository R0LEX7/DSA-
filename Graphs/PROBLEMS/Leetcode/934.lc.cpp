#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
vector<vector<int>> grid;
int n ;
int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

void dfs(int i , int j){

    grid[i][j] = 2;

    for(auto&[dx , dy] : dir){
        int x = i + dx , y = j + dy;

        if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1 ) continue;

        dfs(x , y);
    }
}

public:
    int shortestBridge(vector<vector<int>>& mat) {
        this->grid = mat;
        this->n = mat.size();


        bool found = false;
        for(int i = 0 ; i < n && !found ; ++i){
            for(int j = 0 ; j < n ;++j){
                if(grid[i][j] == 1){
                    dfs(i , j);
                    found = true;
                    break;
                }
            }
        }


        queue<pair<int , pair<int , int>>> q;
        vector<vector<int>> vis(n , vector<int>(n , 0));



        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ;++j){
                if(grid[i][j] == 2){
                    q.push({0 , {i , j}});
                    vis[i][j] = 1;
                };
            }
        }

        while(!q.empty()){
            auto [currDis , pos] = q.front(); q.pop();
            auto [i , j] = pos;

            if(grid[i][j] == 1) return currDis;

            for(auto&[dx , dy] : dir){
                int x = i + dx , y = j + dy;

                if(x < 0 || y < 0 || x >= n || y >= n || vis[x][y] ) continue;

                vis[x][y] = 1;

                q.push({currDis +1 , {x,y}});

            }
        }

        return -1;
    }
};

int main(){

    return 0;
}