#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<int>> image;
    vector<vector<int>> copy;
    int color ;
    int newColor ;

    void dfs(int i , int j){
        if(image[i][j] != color || copy[i][j]  == newColor) return;

        copy[i][j] = newColor;

        int n = copy.size() , m = copy[0].size();

        int dx[] = {0,0 , 1 ,-1};
        int dy[] = {1 ,-1 , 0 , 0};

        for(int k = 0 ; k < 4 ; k++){
            int x = i + dx[k] , y = j + dy[k];
            if((x >= 0 && x < n) && (y >= 0 && y < m)){
                dfs(x , y);
            }
        }
    }

      vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                    int newColor) {
          this->newColor =newColor;
          this->image = image;
          this->copy = image ;
          this->color = image[sr][sc];

          dfs(sr , sc);

          return this->copy;
      }
  };


int main(){

    return 0;
}