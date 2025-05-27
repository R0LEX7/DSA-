#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool help(int day, int n, int m, vector<vector<int>>& cells) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < day; ++i) {
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; ++j) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }

        vector<pair<int, int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == n-1) return true;
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !grid[nx][ny] && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    public:
        int latestDayToCross(int n, int m, vector<vector<int>>& cells) {
        int low = 1, high = cells.size(), ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (help(mid, n, m, cells)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    };
int main(){

    Solution sol;
    int row3 = 3;
    int col3 = 3;
    vector<vector<int>> cells3 = {
        {1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}
    };
    int output3 = sol.latestDayToCross(row3, col3, cells3);
    cout << "Output 3: " << output3 << endl; // Expected: 3



    return 0;
}