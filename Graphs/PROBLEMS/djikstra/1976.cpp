#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int countPaths(int n, vector<vector<int>>& roads) {
          vector<vector<pair<int,int>>> adj(n);

          for( auto& road : roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
          }

          int mod = (int)(1e9 + 7);

          vector<long long> dis(n, LLONG_MAX);
          vector<int> ways(n, 0);

          priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;


            // {distance , node}
            pq.push({0,0});
            ways[0] = 1;
            dis[0] = 0;

            while(!pq.empty()){
                long long d = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                if (node == n - 1) break;
                for(auto&p : adj[node]){
                    int child = p.first;
                    long long childD = p.second + d;

                    if(childD < dis[child]){
                        dis[child] = childD;
                        ways[child] = ways[node];
                        dis[child] = childD;
                        pq.push({childD, child});
                    }

                    if(dis[child] == childD) ways[child] = (ways[child] + ways[node]) % 1000000007;
                }
            }

            return ways[n-1];
      }
  };


int main(){
    Solution sol ;


    int n = 7;

    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3},
    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    cout << sol.countPaths(n , roads) << endl;

    return 0;
}
