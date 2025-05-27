#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    vector<vector<int>> getAdjacent(int n, vector<vector<int>>& edges, vector<int>& ind) {
        vector<vector<int>> adj(n);
        for (auto& ed : edges) {
            int u = ed[0], v = ed[1];
            adj[u].push_back(v);
            ind[v]++;
        }
        return adj;
    }

    void getAllAncestors(vector<vector<int>> &grid, int val, unordered_set<int>& s) {
        s.emplace(val);
        for (int x : grid[val]) {
            if (!s.count(x)) // avoid revisiting
                getAllAncestors(grid, x, s);
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> ind(n);
        vector<vector<int>> adj = getAdjacent(n, edges, ind), ans(n), temp(n);

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (ind[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int child : adj[node]) {
                temp[child].push_back(node);
                ind[child]--;
                if (ind[child] == 0) q.push(child);
            }
        }


        for (int i = 0; i < n; ++i) {
            unordered_set<int> s;
            for (int x : temp[i]) {
                getAllAncestors(temp, x, s);
            }

            vector<int> arr(s.begin(), s.end());
            sort(arr.begin(), arr.end());
            ans[i] = arr;
        }

        return ans;
    }
};


int main(){

    return 0;
}
