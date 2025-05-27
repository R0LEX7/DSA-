#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<pair<string , int>> q;
        unordered_set<string> st(wordList.begin() , wordList.end());

        q.push({beginWord , 1});
        st.erase(beginWord);

        while(!q.empty()){
        string word = q.front().first;
        int level = q.front().second;

        q.pop();
        if(word == endWord) return level;

        for(int i = 0 ; i< word.size(); ++i){
            char og = word[i];

            for(char ch = 'a' ; ch <= 'z' ; ++ch){
                word[i] = ch;
                if(st.find(word) != st.end()){
                    q.push({word , level+1});
                    st.erase(word);
                }
            }
            word[i] = og;
        }
        }

        return 0;
    }
};


int main(){

    return 0;
}
