#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int shortestPathAllKeys(vector<string>& grid) {
            int keys = 0 ;
            pair<int , int> src = {-1 , -1};
            int n = grid.size() , m = grid[0].size();

            for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < m ; ++j){
                    char ch = grid[i][j];
                    if(ch == '@') src = {i , j};

                    if(ch >= 'a' && ch <= 'z') keys++;

                }
            }

            vector<vector<int>> vis( n , vector<int>(m , keys));

            unordered_set<char> keysFound;

            vector<pair<int , int>> dir = {{0,1} , {1,0} , {-1,0} , {0 , -1}};

            queue <pair <int , pair<int , int>>> q;
            q.push({0,src});

            vis[src.first][src.second] = vis[src.first][src.second] - 1;

            while(!q.empty()){

                auto& [steps , p] = q.front() ; q.pop();
                auto& [x , y] = p;

                if(keysFound.size() == keys) return steps;

                for(auto& [dx , dy] : dir){
                   int  a =  x+ dx , b = y+dy;

                    if(a < 0 || b < 0 || a >= n || b >= m || grid[a][b] == '#' || vis[a][b] <= 0) continue;

                    vis[a][b] = vis[a][b] -1;

                    char ch = grid[a][b];

                    if(ch >= 'a' && ch <= 'z' && keysFound.count(ch) == 0) keysFound.insert(ch);

                    if(ch >= 'A' && ch <= 'Z'){
                        char key = (char) tolower(ch);
                        if(keysFound.count(key)){
                            keysFound.erase(key);
                        }else continue;
                    }

                    q.push({steps + 1 ,{a,b}});

                }

            }

            return -1;
        }
    };

int main(){

    return 0;
}