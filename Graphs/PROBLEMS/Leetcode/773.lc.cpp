#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int slidingPuzzle(vector<vector<int>>& board) {
            vector<vector<int>> dir = {{1, 3}, {0, 4, 2}, {1, 5}, {0, 4}, {1, 3, 5}, {4, 2}};

            string target = "123450";
            string curr = "";

            for(auto& arr : board) {
                for(int x : arr) {
                    curr += to_string(x);
                }
            }

            set<string> vis;
            vis.insert(curr);

            queue<string> q;
            q.push(curr);

            int ans = 0;

            while(!q.empty()) {
                int sz = q.size();

                while(sz--) {
                    string current = q.front(); q.pop();

                    if(current == target) return ans;

                    int zeroInd = current.find('0');

                    for(int nextZeroInd : dir[zeroInd]) {
                        string nextComb = current;
                        swap(nextComb[zeroInd], nextComb[nextZeroInd]);

                        if(vis.count(nextComb)) continue;
                        vis.insert(nextComb);
                        q.push(nextComb);
                    }
                }
                ans++;
            }

            return -1;
        }
    };


int main(){

    return 0;
}
