#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int largestPathValue(string colors, vector<vector<int>>& edges) {
            int n = colors.size();

            vector<int> ind(n , 0);

            vector<vector<int>> adj(n);

            for(auto& edge : edges){
                int u = edge[0] , v = edge[1];
                adj[u].push_back(v);
                ind[v]++;
            }

            queue<int> q;

            for(int i = 0 ; i < n ; ++i){
                if(ind[i] != 0) continue;
                q.push(i);
            }

            // count ka vector

            vector<vector<int>> count( n , vector<int>(26 , 0));

            for( int i = 0 ; i<n ; ++i){
                count[i][colors[i] - 'a']++;
            }

            int maxi = 0 , vis = 0;

            while(!q.empty()){
                int node = q.front() ; q.pop();
                vis++;

                for(int child : adj[node]){
                    for(int i = 0 ; i < 26 ; ++i){
                        count[child][i] = max(count[child][i] , (count[node][i] + (colors[child] - 'a' == i ? 1 : 0)) );
                    }
                    ind[child]--;

                    if(ind[child] == 0) {
                        q.push(child);
                    }
                }
                maxi = max(maxi , *max_element(count[node].begin() , count[node].end()));
            }

            if(vis != n) return -1;

            return maxi;

        }
    };

int main(){

    return 0;
}