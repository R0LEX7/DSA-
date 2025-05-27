#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int start , vector<pair<int , int>>& ans , unordered_map<int , stack<int>>& adj){
        auto& st = adj[start];

        while(!st.empty()){
            int neigh = st.top(); st.pop();

            dfs(neigh , ans , adj);

            ans.emplace_back(start , neigh);
        }


    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int , stack<int>> adj ;
        unordered_map<int , int> ind , out;

        for(auto&it : pairs){
            int u = it[0] , v = it[1];

            adj[u].push(v);
            out[u]++;
            ind[v]++;
        }

        int start ;

        for(auto& [node , _] : adj){
            if(out[node] - ind[node] == 1){
                start = node;
                break;
            }
        }

        vector<pair<int , int>> ans;

        dfs(start , ans , adj);

        reverse(ans.begin() , ans.end());

        vector<vector<int>> res;

        for(auto& [u , v] : ans) res.push_back({u , v});

        return res;
    }
};

int main(){

    return 0;
}