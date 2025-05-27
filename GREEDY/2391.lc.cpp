#include <bits/stdc++.h>
using namespace std;

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> lastInd(3,-1);

        int cost = 0;

        for (int i = 0; i < garbage.size(); i++) {
            string s = garbage[i];
            for (char ch : s) {
                if (ch == 'G') lastInd[0] = i;
                if (ch == 'M') lastInd[1] = i;
                if (ch == 'P') lastInd[2] = i;
            }
        }

        for(int i=0 ; i < garbage.size() ; i++){
            string s = garbage[i];
            cost += s.size(); // add picking cost

            if(i>0){
                if(i<= lastInd[0]) cost += travel[i-1];
                if(i<= lastInd[1]) cost += travel[i-1];
                if(i<= lastInd[2]) cost += travel[i-1];
            }

        }

        return cost;
}


int main(){

    return 0;
}
