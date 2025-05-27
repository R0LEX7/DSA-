#include <bits/stdc++.h>
using namespace std;

    int maxArea(vector<int>& arr) {
        int n = arr.size() , r = n-1 , l = 0, area = -1;

        while(l<r){
            int ar = min(arr[l] , arr[r]) * (r-l);
            area = max(area , ar);

            if(arr[l] < arr[r]) l++;
            else r--;
        }

        return area;
    }


int main(){

    return 0;
}
