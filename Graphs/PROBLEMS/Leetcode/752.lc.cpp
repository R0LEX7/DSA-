#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> vis;

        for(string s : deadends) vis.emplace(s);

        if(vis.count("0000")) return -1;

        queue<pair<int , string>> q;

        q.push({0 , "0000"});

        vis.emplace("0000");

        while(!q.empty()){

            auto [steps , str] = q.front(); q.pop();

            if(str == target) return steps;

            for(int i =0 ; i < 4 ; ++i){

                char ch = str[i];

                string s = str;

                if(ch == '9' || ch == '0'){
                    if(ch == '0'){
                        string temp = s;
                        temp[i] = '1';
                        if(vis.count(temp) == 0){
                            q.push({steps + 1 ,temp });
                            vis.emplace(temp);
                        }
                        temp= s;
                        temp[i] = '9';
                        if(vis.count(temp) == 0){
                            q.push({steps + 1 ,temp });
                            vis.emplace(temp);
                        }
                    }else{
                        string temp = s;
                        temp[i] = '0';
                        if(vis.count(temp) == 0){
                            q.push({steps + 1 ,temp });
                            vis.emplace(temp);
                        }
                        temp= s;
                        temp[i] = '8';
                        if(vis.count(temp) == 0){
                            q.push({steps + 1 ,temp });
                            vis.emplace(temp);
                        }
                    }
                }else{
                     string temp = s;
                        temp[i] = ((ch - '0') - 1) + '0';
                       if(vis.count(temp) == 0){
                            q.push({steps + 1 ,temp });
                            vis.emplace(temp);
                        }
                        temp= s;
                        temp[i] = ((ch - '0') + 1) + '0';
                        if(vis.count(temp) == 0){
                            q.push({steps + 1 ,temp });
                            vis.emplace(temp);
                        }

                }

            }
        }

        return -1;

    }
};

int main(){

    cout<<stoi("1") + stoi("2")<<endl;

    return 0;
}