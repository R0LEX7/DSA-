#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(vector<vector<int>> & adj , int s , vector<int>& vis , int& cnt){
        if(vis[s]) return;

        vis[s] = 1;
        cnt++;

        for(int n : adj[s]){
            if(vis[n]) continue;

            dfs(adj , n , vis , cnt );

        }
    }
    public:
        int maximumDetonation(vector<vector<int>>& bombs) {

            int n = bombs.size();

            vector<vector<int>> adj(n);

            for(int i = 0 ; i < n ; ++i){
               long long  x = bombs[i][0], y = bombs[i][1] , r = bombs[i][2];

                for(int j = 0 ; j < n ; ++j){
                    if(i == j) continue;

                    long long a = abs(x - bombs[j][0]) , b = abs(y - bombs[j][1]);

                    if(a*a + b*b > r*r) continue;

                    adj[i].push_back(j);

                }
            }

            int ans = 0;



            for(int i = 0 ; i < n ; ++i){

                int cnt = 0;
                vector<int> vis(n , 0);
                dfs(adj , i , vis , cnt);

                ans = max(ans , cnt);
            }

            return ans;

        }
    };

int main(){

    vector<vector<int>> arr = {{2,1,3} , {6,1,4}};
    Solution sol;

    int ans = sol.maximumDetonation(arr);

    cout<<ans;

    return 0;
}