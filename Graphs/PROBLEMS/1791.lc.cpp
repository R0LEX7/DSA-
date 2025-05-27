#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findCenter(vector<vector<int>>& edges) {
            unordered_map<int , int> inDegree ;

            for(auto& edge : edges){
                inDegree[edge[0]]++;
                inDegree[edge[1]]++;
            }

            int n = inDegree.size();

            for(int i = 1 ; i <= n ; ++i){
                if(inDegree[i] == n-1) return i;
            }

            return -1;
        }
    };


    int main(){

        return 0;
    }