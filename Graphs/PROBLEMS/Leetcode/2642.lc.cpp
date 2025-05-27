#include <bits/stdc++.h>
using namespace std;

class Graph {
    private:
    vector<vector<pair<int ,int>>> adj;
    int n;
    public:
        Graph(int n, vector<vector<int>>& edges) {
            adj.resize(n);
            this->n = n;
            for(auto& it : edges){
                int u = it[0] , v = it[1] ,d = it[2];
                adj[u].push_back({v ,d});
            }
        }

        void addEdge(vector<int> edge) {
            int u = edge[0] , v = edge[1] ,d = edge[2];
                adj[u].push_back({v ,d});

        }

        int shortestPath(int u, int v) {

            priority_queue< pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
            vector<int> dist(n , 1e8);

            pq.push({u , 0});
            dist[u] = 0;

            while(!pq.empty()){
                auto [node , distance] = pq.top() ; pq.pop();

                for( auto& p : adj[node]){
                    auto [child , childDis] = p;

                    if(childDis + distance < dist[child]){
                        dist[child] = childDis+ distance;
                        pq.push({child , childDis+ distance });
                    }
                }
            }

            return dist[v] == 1e8 ? -1 : dist[v];
        }
    };


int main(){

    return 0;
}
