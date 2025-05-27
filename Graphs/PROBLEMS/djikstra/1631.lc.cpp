#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            priority_queue <pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>> > pq;

            int n = heights.size() , m = heights[0].size();

            vector<vector<int>> dis(n , vector<int>(m , 1e9));


            // {dis , {x,y}}
            pq.push({0 , {0 , 0}});
            dis[0][0] = 0;

            while(!pq.empty()){
                int d = pq.top().first , x = pq.top().second.first , y = pq.top().second.second;
                pq.pop();



                if(x == n-1 && y == m-1) return d;

                vector<pair<int , int>> dir = {{0,1} , {1,0} , {0,-1} , {-1,0}};

                for(auto cordinates : dir){
                    int a = x + cordinates.first , b = y + cordinates.second ;

                    if(a < 0 || a >= n || b < 0 || b >= m) continue;

                    int childDis = max(d , abs(heights[x][y] - heights[a][b]));

                    if(dis[a][b] <= childDis) continue;

                    dis[a][b] = childDis;

                    pq.push({childDis , {a , b}});

                }

            }

            return 0;
        }
    };


int main(){
    Solution sol;

    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    cout<<sol.minimumEffortPath(heights);



    return 0;
}
