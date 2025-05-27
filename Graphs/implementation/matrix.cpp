#include <bits/stdc++.h>
using namespace std;


int main(){
    int n , m;
    cin>> n;
    cin>> m;

    int adj[n+1][n+1];

    for(int i = 0 ; i < m ; ++i){
        int u , v;
        cin >> u;
        cin >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    };

    for(int i = 0 ; i < n+1 ; i++){
        for(int j = 0 ; j < n+1 ; j++){
            if(adj[i][j] ==1){
                cout<<i << "-" << j <<endl;
            }
        }
    }

    return 0;
}