#include <bits/stdc++.h>
using namespace std;


int main(){
int n , m ;
cin >> n >> m;

vector<int> adj[n+1] ;


for(int i = 0 ; i < m ; ++i){
    int u ,v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);

}

for(int i = 0 ; i < n+1 ; i++){
    string path = "";
    for(int j = 0 ; j < adj[i].size() ; ++j){
        path += to_string(adj[i][j]);
    }
    cout<<i<<" - " << path<<endl;
}

    return 0;
}
