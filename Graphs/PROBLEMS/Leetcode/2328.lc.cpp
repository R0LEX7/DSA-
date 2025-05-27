#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int mod = 1e9 + 7;

    int dfs(int i , int j , int n , int m , vector<vector<int>>& grid , vector<vector<int>>& dp ){
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1;

        vector<pair<int , int>> dir = {{1,0} , {0 ,1} , {0,-1} , {-1,0}};

        for(auto&[a , b] : dir){
            int x = a + i , y = b + j;

            if(x < 0 || y < 0 || x > n || y > m || grid[i][j] >= grid[x][y]) continue;

            ans = (ans%mod  + dfs(x,y , n , m , grid , dp)%mod)%mod;
        }

        return dp[i][j] = ans%mod;
    }

    public:
        int countPaths(vector<vector<int>>& grid) {
            int n = grid.size() , m = grid[0].size();
            vector<vector<int>> dp(n , vector<int>(m , -1));

            long long count = 0 ;

            for(int i = 0 ; i < n ; i++){
                for( int j = 0 ; j < m ; ++j){
                    count = (count%mod + dfs(i , j , n , m , grid , dp)%mod)%mod;
                }
            }

            return (int)count%mod;
        }
    };

int main(){

    return 0;
}