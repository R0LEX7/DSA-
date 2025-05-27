#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
                priority_queue<int> pq;
                int limitInd = 0;

                for(int i = 0 ; i < grid.size() ; i++){
                    priority_queue<int> temp;
                    for(int j = 0 ; j < grid[i].size() ; j++){
                        temp.push(grid[i][j]);
                    }

                    for(int j = 0 ; j < limits[i] ; j++){
                        pq.push(temp.top());
                        temp.pop();
                    }
                }

                long long sum = 0;
                for(int i = 0 ; i < k ; i++){
                    sum += pq.top();
                    pq.pop();
                }

                return sum;
        }
    };


int main(){

    return 0;
}