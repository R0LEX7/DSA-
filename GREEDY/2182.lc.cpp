#include <bits/stdc++.h>
using namespace std;

string repeatLimitedString(string s, int k) {
        string ans = "";
        unordered_map<char , int> map;
        priority_queue<char> pq;

        for (char c : s) map[c]++;

        for(auto [s , x] : map) pq.push(s);

        char lastEle = '0' ;

        while(!pq.empty()){
            char top = pq.top();
            pq.pop();

            int addCount = min(k, map[top]);
        ans += string(addCount, top); // Append `addCount` instances of `top`
        map[top] -= addCount;

            if(map[lastEle] > 0){
                pq.push(lastEle);
                lastEle = top;
            }
        }

        return ans;
    }


int main(){

    return 0;
}
