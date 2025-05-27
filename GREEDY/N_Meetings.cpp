#include <bits/stdc++.h>
using namespace std;

int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int ans = 1 , limit = end[0] , n = start.size();

        for(int i = 1 ; i < n ; i++){
            if(start[i] > limit) {
                ans++;
                limit = end[i];
            }
        }
        return ans;
    }


int main(){

 vector<int> s ={10,12,20} , e = {20,25,30};

 cout<<maxMeetings(s,e)<<endl;

    return 0;
}
