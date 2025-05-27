#include <bits/stdc++.h>
using namespace std;


/**
 * @brief
 * Strongly Connected Component(SCC):
A component is called a Strongly Connected Component(SCC) only if for every possible pair of vertices (u, v) inside that component, u is reachable from v and v is reachable from u.
 *
 */
class Solution {
    public:
     void dfs(vector<vector<int>> &adj , vector<int>& vis , int s , vector<int>& ans , vector<int>& st , bool flag){

        vis[s] = 1;
        if(flag) ans.push_back(s);
        for(int n : adj[s]){
            if(vis[n]) continue;
            dfs(adj , vis , n , ans , st , flag);
        }

        if(!flag)st.push_back(s);
     }
      int kosaraju(vector<vector<int>> &adj) {
          // code here
          int n = adj.size();
          vector<int> st , tempo , vis(n , 0);
        vector<vector<int>> ans;
          for(int i = 0 ; i < n ; ++i){
            if(vis[i]) continue;
            dfs(adj , vis , i , tempo , st , false);
           }

           fill(vis.begin(), vis.end(), 0);
           vector<vector<int>> reverseAdjacent(n);

           for(int i = 0 ; i < n ; i++){
            for (int j : adj[i]) {
                reverseAdjacent[j].push_back(i);
            }
           }

           int sccCount = 0;

           while(!st.empty()){
            int node = st.back();
            st.pop_back();
            vector<int> temp;
            if(vis[node]) continue;
            dfs(reverseAdjacent , vis , node , temp , st , true);
            ans.push_back(temp);
            sccCount++;

           }


           return ans.size();

      };




  };


int main(){

    return 0;
}
