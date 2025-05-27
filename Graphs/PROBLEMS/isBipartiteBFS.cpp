#include <bits/stdc++.h>
using namespace std;

bool bfs(int s , vector<vector<int>> &adj , vector<int> &col){


    queue<int> q;
    q.push(s);
    col[s] = 0 ;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto x : adj[node]){

                if(col[x] == -1){
                    q.push(x);
                    col[x] = !col[node];
                }else if(col[x] == col[node]) return false;

        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& adj) {
 int n = adj.size();

 vector<int> col(n , -1);

 for(int i = 0 ; i < n ; ++i){
    if(col[i] == -1){
        if(bfs(i , adj , col) == false) return false;
    }
 }

 return true;

}




int main(){

    vector<vector<int>> adj = {{1}, {0,2}, {1}};

    cout<<isBipartite(adj)<<endl;

    return 0;
}