#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to find sum of weights of edges of the Minimum Spanning Tree.
      int spanningTree(int V, vector<vector<int>> adj[]) {
          // code here
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //   {weight , node}

        pq.push({0 ,0});

        int ans = 0;

        vector<int> vis(V , 0);

        while(!pq.empty()){
            int node = pq.top().second , weight = pq.top().first;
            pq.pop();

            if(vis[node]) continue;

            vis[node] = 1;

            ans += weight;

            for(auto arr : adj[node]){
                if(vis[arr[0]]) continue;
               pq.push({arr[1] , arr[0]});
            }


        }

        return ans;

      }
  };



  int main(){

      return 0;
  }