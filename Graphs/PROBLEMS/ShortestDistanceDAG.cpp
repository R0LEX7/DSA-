#include <bits/stdc++.h>
using namespace std;



class Solution {
    public:
    void topoSort(vector<vector<pair<int , int>>>& adj , int s , vector<int>& vis , stack<int> &st){

        vis[s] = 1;

        for(auto& node : adj[s]){
            int n = node.first ;

            if(vis[n]) continue;

            topoSort(adj ,  n , vis , st);
        }

        st.push(s);

    }
      vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        int s = 0;
        for(auto& arr : edges){
            adj[arr[0]].push_back({arr[1] , arr[2]});
        }
        vector<int> vis(V , 0);
        stack <int> st ;
        vector<int> dis(V , INT_MAX);
        dis[s] = 0;

        for(int i = 0 ; i < V ; ++i){
            if(vis[i]) continue;
            topoSort(adj , i , vis , st);
        }

        while(!st.empty()){
            int node = st.top();

            st.pop();

            int d = dis[node];

            if (dis[node] != INT_MAX) {

            for(auto& p : adj[node]){
                // dis[p.first] = min( (d + p.second) , dis[p.first]);
                if(d + p.second <  dis[p.first]){
                    dis[p.first] = d + p.second;
                }
            }
        }

        }

        for(int i = 0 ; i < V ; ++i){
            if(dis[i] != INT_MAX) continue;
            dis[i] = -1;
        }
        return dis;
      }
  };


int main(){

    Solution sol;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}
    };

    vector<int> ans = sol.shortestPath(6,7,edges);

    for(int x: ans){
        cout<<x<<endl;
    }

    return 0;
}
