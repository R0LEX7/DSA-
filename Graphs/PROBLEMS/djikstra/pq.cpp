
  #include <bits/stdc++.h>
  using namespace std;

class Solution {
    public:
      // Function to find the shortest distance of all the vertices
      // from the source vertex src.
      vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        vector<int> dis(n , 1e9);
        priority_queue <pair<int , int>, vector<pair<int , int>> , greater<pair<int , int>> > pq;

        pq.push({0,src});
        dis[src] = 0;

        while(!pq.empty()){
            int d = pq.top().first , node = pq.top().second;
            pq.pop();

            for(auto& p : adj[node]){
                int child = p.first , childDis = p.second + d;

                if(dis[child] < childDis) continue;
                dis[child] = childDis;
                pq.push({childDis , child});
            }

        }

        for(int i = 0 ; i < n ; ++i){
            if(dis[i] != 1e9) continue;

            dis[i] = -1;
        }

        return dis;
      }
  };


  int main(){
    Solution sol;
    vector<vector<pair<int, int>>> adj = {{{1, 9}}, {{0, 9}}};

    vector<int> ans = sol.dijkstra(adj , 0);

    for(int x: ans){
        cout<<x;
    }

      return 0;
  }
