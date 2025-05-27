#include <bits/stdc++.h>
using namespace std;

int help(vector<vector<int>> arr){


    set<pair<int , int>> s;

    for (const auto& circle : arr) {
            int x_c = circle[0], y_c = circle[1], r = circle[2];

            for (int x = x_c - r; x <= x_c + r; x++) {
                for (int y = y_c - r; y <= y_c + r; y++) {
                    // Check if (x, y) is inside the circle
                    if ((x - x_c) * (x - x_c) + (y - y_c) * (y - y_c) <= r * r) {
                        s.insert({x, y});
                    }
                }
            }
        }

    return s.size() + 1;
}


int main(){

    vector<vector<int>> arr = {{3,4,1} , {2,2,2}};
    int ans  = help(arr);
    cout<<ans;

    return 0;
}
