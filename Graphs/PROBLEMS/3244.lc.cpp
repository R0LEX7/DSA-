#include <bits/stdc++.h>
using namespace std;

class Solution {
    private :
    void removeFromSet (set <int> &nodeSet , int r , int l){
        for(int i = l ; i < r ; ++i){
            nodeSet.erase(i);
        }
    }
    public:
        vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
           vector<int> res;



            set<int> nodeSet;

            for(int i = 0 ; i < n ; ++i){
                nodeSet.insert(i);
            }

            for(auto& q : queries){
                int l = q[0] + 1 , r = q[1];
                removeFromSet(nodeSet , r , l);
                res.push_back(nodeSet.size() -1);
            }


            return res;

        }
    };


int main(){

    return 0;
}