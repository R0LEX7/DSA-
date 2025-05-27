#include <bits/stdc++.h>
using namespace std;

class Solution {

    public:
    vector<vector<int>> vis;
    vector<vector<char>> mat;


        void dfs(int i , int j){
            if(vis[i][j]) return;

            vis[i][j] = 1;

            int dx[] = {1,-1,0,0};
            int dy[] = {0,0,1,-1};

            int n = mat.size() , m = mat[0].size();

            for(int k = 0 ; k< 4 ; ++k){
                int x = i + dx[k] , y = j + dy[k];
                if((x >= 0 && x < n) && (y >= 0 && y < m) && mat[x][y] == 'O'){
                    dfs(x,y);
                }
            }

        }
      vector<vector<char>> fill(vector<vector<char>>& mat) {
          int n = mat.size() , m = mat[0].size();
          char ch = 'O';

          vis.assign(n , vector<int>(m , 0));
          this->mat = mat;

          for(int j = 0 ; j < m ; ++j){
            if(mat[0][j] == ch) dfs(0 , j);

            if(mat[n-1][j] == ch) dfs(n-1 , j);
          }

          for(int i= 0 ; i< n ; ++i){
            if(mat[i][0] == ch) dfs(i , 0);

            if(mat[i][m-1] == ch) dfs(i , m-1);
          }

          for(int i= 0 ; i< n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(vis[i][j] == 1) continue;
                mat[i][j] = 'X';
              }
          }

          return mat;

      }

      vector<vector<int>> f(){
        return this->vis;
      }
  };

int main(){
    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}
    };

    Solution ob;

    vector<vector<char>> res = ob.fill(mat);
    vector<vector<int>> ans = ob.f();

    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 4;j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
