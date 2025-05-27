#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj)
    {
        queue<int> q;
        int n = adj.size();
        vector<int> vis(n + 1, 0);
        q.push(0);
        vector<int> bfs;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            bfs.push_back(node);
            for (int i = 0; i < adj[node].size(); ++i)
            {
                if (vis[adj[node][i]])
                    continue;

                // not visited
                q.push(adj[node][i]);
                vis[adj[node][i]] = 1;
            }
        }

        return bfs;
    }
};

int main()
{

    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    Solution sol;
    vector<int> ans = sol.bfsOfGraph(adj);

    for (int x : ans)
    {
        cout << x << endl;
    }

    return 0;
}