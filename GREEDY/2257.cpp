#include <bits/stdc++.h>
using namespace std;


 int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        set <pair<int,int>> wset;
        for( auto arr : walls){
            wset.insert({arr[0] , arr[1]});
        }

        set <pair<int,int>> gset ;

        for(auto arr : guards){
            int y= arr[0] , x = arr[1];

            gset.insert({y,x});

            // down
            for(int i = y +1 ; i < m ; i++){
                int xc = x , yc = i;
                if(wset.find({yc,xc}) != wset.end()) break;
                gset.insert({yc,xc});
            }

            // up
            for(int i = y ; i>=0 ; i--){
                int xc = x , yc = i;
                if(wset.find({yc,xc}) != wset.end()) break;
                gset.insert({yc,xc});
            }

            // left
            for(int i = x ; i>=0 ; i--){
                int xc = i , yc = y;
                if(wset.find({yc,xc}) != wset.end()) break;
                gset.insert({yc,xc});
            }

            // right
            for(int i = x ; i < n ; i++){
                int xc =  i , yc = y;
                if(wset.find({yc,xc}) != wset.end()) break;
                gset.insert({yc,xc});
            }
        }

        return n * m - (wset.size());
    }

int main(){



    return 0;
}
