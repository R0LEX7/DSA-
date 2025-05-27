#include <bits/stdc++.h>
using namespace std;

static bool compare(vector<int> a , vector <int> b) {
    return a[1] < b[1];
}

vector<int> help(vector<vector<int>>& rectangles, vector<vector<int>>& points){
    int n = rectangles.size() ;

    sort(rectangles.begin() , rectangles.end(), compare);

    vector <int> ans(points.size() , 0);
    int j = 0;

    for(auto& point : points){
        int x = point[0] , y = point[1] , s = 0 , e = n-1;

        while(s <= e){
            int mid = s + (e-s)/2;

            int a = rectangles[mid][0] , b = rectangles[mid][1];


            if(a >= x && b >= y){
                if(mid > 0 && rectangles[mid - 1][0] >= x && rectangles[mid -1][0] >= y) e = mid -1;
                else{
                ans[j++] = (n-mid);
                break;
                }
            }else if ( b < y) s = mid +1;
            else e = mid -1;
        }

    }

    return ans;
}


int main(){



    return 0;
}
