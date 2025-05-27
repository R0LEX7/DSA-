#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

vector<int> flattenedList(vector<vector<int>>& board){
    int n = board.size() , ind = 1;;

    vector<int> arr(n*n +1 , -1);

    bool leftToRight = true;

    for(int row = n-1 ; row >=0 ; --row){
        if(leftToRight){
            for(int col = 0 ; col <n ; ++col){
                arr[ind++] =board[row][col];
            }
        }else{
            for(int col = n-1 ; col >=0 ; --col){
                arr[ind++] =board[row][col];
            }
        }
        leftToRight = !leftToRight;
    }

    return arr;
}
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size() , moves = 0;
        vector<int> arr = flattenedList(board) , vis(n*n +1 , 0);

        queue<int> q;
        q.push(1);

        vis[1] = 1;

        while(!q.empty()){

            int sz = q.size();

            while(sz--){
                int curr = q.front(); q.pop();

                if(curr == n*n) return moves;

                for(int i = 1 ; i <= 6 ; ++i){
                    int next = curr + i;

                    if(next > n*n) continue;
                    int dest = arr[next] == -1 ? next : arr[next];

                    if(vis[dest]) continue;

                    vis[dest] = 1;
                    q.push(dest);
                }
            }

            moves++;
        }

        return -1;


    }
};

int main(){

    return 0;
}
