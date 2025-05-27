#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
            unordered_map<int , vector<int>> map;
            unordered_map <int , int> ind;

            for(auto& edge : adjacentPairs){
                map[edge[0]].push_back(edge[1]);
                map[edge[1]].push_back(edge[0]);

                ind[edge[0]]++;
                ind[edge[1]]++;
            }

            int src ;

            for (auto& it : ind) {
                cout<<it.first << " "<< it.second<<endl;
               if(it.second == 1){
                src = it.first;
                break;
               }
            }

            cout<<src<<endl;
            queue<int> q;
            q.push(src);

            int n = ind.size();

            vector<int>  ans;
            set <int> vis;
            vis.insert(src);

            while(!q.empty()){
                int node = q.front() ; q.pop();

                ans.push_back(node);

                for(int adj : map[node]){
                    if(vis.count(adj)) continue;

                    q.push(adj);

                    vis.insert(adj);
                }
            }

            return ans;
        }
    };


int main(){

    vector<vector<int>> arr = {{2,1} , {3,4} , {3,2}};
    Solution sol;

    vector<int> ans = sol.restoreArray(arr);

    for(int x : ans) cout<< x;

    return 0;
}