#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
            unordered_map<int , vector<int>> busIds;

            int r = routes.size();

            for(int i = 0 ; i < r ; ++i){
                for(int j : routes[i]){
                    busIds[j].push_back(i);
                }
            }

            queue<pair<int , int>> q;
            q.push({source , 0});
            // {busStop , bus}

            unordered_map<int , bool> visBus , visBusStop;

            while(!q.empty()){
                int sz = q.size();

                while(sz--){
                    auto [currStop , noOfBus] = q.front() ; q.pop();

                    if(currStop == target) return noOfBus;

                    for(int bus : busIds[currStop]){
                        if(visBus[bus]) continue;
                        visBus[bus] = true;

                        for(int stop : routes[bus]){
                            if(visBusStop[stop]) continue;
                            visBusStop[stop] = true;

                            q.push({stop , noOfBus +1});
                        }
                    }
                }
            }

            return -1;
        }
    };


int main(){

    return 0;
}