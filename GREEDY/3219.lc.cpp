#include <bits/stdc++.h>
using namespace std;

 long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.rbegin() , horizontalCut.rend());
        sort(verticalCut.rbegin() , verticalCut.rend());

        long long cost = 0;
        int hp = 1 , vp = 1 , i = 0 , j = 0;

        while(i< m-1 && j < n-1){
            if(j == n-1 || (i < m-1 && horizontalCut[i] >= verticalCut[i])){
                cost += (long long) horizontalCut[i]* vp;
                hp++;
                i++;
            }else{
                cost += (long long) verticalCut[j]* hp;
                vp++;
                j++;
            }
        }
    return cost;

    }


int main(){

    return 0;
}