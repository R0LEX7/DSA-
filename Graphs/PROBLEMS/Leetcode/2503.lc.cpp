#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {

        int n = grid.size() , m = grid[0].size() , cnt = 0;


        vector<int> ans(queries.size());

        unordered_map <int , int> queryToInd;

        for(int i = 0 ; i < queries.size() ; ++i){
            queryToInd[queries[i]]= i;
        }

        sort(begin(queries) , end(queries));

        priority_queue<pair<int , pair<int , int>>, vector<pair<int , pair<int , int>>> , greater<>> pq;

        vector<pair <int , int>> dir = {{0 , 1 } , {0 , 1} , {0 , -1} , {-1 , 0}};

        pq.push({grid[0][0] , {0 , 0}});
        // grid[i][j] , { i , j};

        vector<vector<int>> vis( n , vector<int>(m , 0));

        vis[0][0] = 1;

        for(int q : queries){

            while(!pq.empty() && pq.top().first < q){

                auto [val , pos] = pq.top();

                cnt++;

                for( auto& [a, b] : dir){
                    int x = a + pos.first , y = b + pos.second;

                    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y]) continue;

                    pq.push({grid[x][y] , {x , y} });

                    vis[x][y] = 1;
                }

            }

            ans[queryToInd[q]] = cnt;
        }

        return ans;
    }
};

int main(){

    return 0;
}