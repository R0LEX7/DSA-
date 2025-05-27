#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {

        vector<vector<pair<int , int>>> adj(n);

        // {neighbour , cost}
        for(auto& flight : flights){
            adj[flight[0]].push_back({flight[1] , flight[2]});
        }

        queue<pair<int ,pair<int , int> >> q;
        vector<int> dis(n , 1e9);

        // {stops , {node , cost}}
        q.push({0 , {src , 0}});
        dis[src] = 0;

        while(!q.empty()){
            int stops = q.front().first , node = q.front().second.first , cost = q.front().second.second;
            q.pop();

           if(stops > K) continue;
            for(auto& p : adj[node]){
                int child = p.first , childCost = p.second + cost;

                if(dis[child] < childCost) continue;;

                dis[child] = childCost;
                q.push({stops + 1 , {child , childCost}});
            }

        }
        return dis[dst] == 1e9 ? -1 : dis[dst];
      }
  };


int main(){
    Solution sol ;

    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int n = 4 , src = 0 , dst = 3 , k = 1;

    cout << sol.CheapestFLight(n , flights , src , dst , k) << endl;


    return 0;
}
