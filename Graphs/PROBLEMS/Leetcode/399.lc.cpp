#include <bits/stdc++.h>
using namespace std;


class Solution {

private :

    void dfs(unordered_map<string , vector<pair<string , double>>> &adj , string s , string v , double val , double& res , string parent ){

        res *= val;

        if(s == v) return;


        for(auto& p : adj[s]){
            auto [child , childWt] = p;
            if(child == parent) continue;

            dfs(adj , child , v , childWt , res , s);

        }


    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string , vector<pair<string , double>>> adj;

        int en = equations.size();

        vector<double> ans;

        for(int i = 0 ; i < en ; i++ ){
            string u = equations[i][0] , v = equations[i][1];
            double wt = values[i];

            adj[u].push_back({v , wt});
            cout<<u << "->" << v << wt <<endl;
            adj[v].push_back({u , (1/wt)});
            cout<<v << "->" << u << (1/wt) <<endl;
        }

        for(auto& q : queries){
            string u = q[0] , v = q[1];

            if( u == v && adj.count(u)) {
                ans.push_back(1);
                continue;
            }

            if(adj.count(u) == 0 || adj.count(v) == 0){
                ans.push_back(-1);
                continue;
            }


            double res = 1;

            dfs(adj , u , v , 1 , res  , "");

            ans.push_back(res);
        }

        return ans;
    }
};

int main() {
    // Input
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {
        {"a", "c"},
        {"b", "a"},
        {"a", "e"},
        {"a", "a"},
        {"x", "x"}
    };

    // Example output: [6.00000, 0.50000, -1.00000, 1.00000, -1.00000]

    // Assuming your function is named:
    // vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)

    // Call your function
    Solution sol;
    vector<double> result = sol.calcEquation(equations, values, queries);

    // Print the output
    for (double res : result) {
        cout << fixed << setprecision(5) << res << " ";
    }
    cout << endl;

    return 0;
}
