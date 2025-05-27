#include <bits/stdc++.h>
using namespace std;

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

    priority_queue<int,vector<int>,greater<int> >pq ;
    int ans = -1;

    for(int i = 0 ; i <heights.size() -1 ; i++){
        int gap = heights[i+1] - heights[i] , ans ;

        if(gap > 0){
           if(ladders > 0){
            pq.push(gap);
            ladders--;
           }else {
            if(!pq.empty()){
                if(pq.top() < gap && bricks >= pq.top()){
                   bricks -= pq.top();
                   pq.pop();
                   pq.push(gap);
                }else {
                    if( bricks >= gap) bricks -= gap;
                    else {
                        ans = i+1;
                        break;
                    }
                }
            }else {
                if( bricks >= gap) bricks -= gap;
                else {
                    ans = i+1;
                    break;
                }
            }
           }
        }
    }

    return ans == -1 ? heights.size() -1 : ans;
}


int main(){

    return 0;
}
