#include <bits/stdc++.h>
using namespace std;


class Solution {

    private :

    vector<int> topoSort( unordered_map<int , int>& ind  , vector<vector<int>> &adj , int k){
        int  vis = 0;
        vector<int> ans;

        queue<int> q;

        for( auto& [key , value] : ind){
            if(value == 0) q.push(key);
        }

        while(!q.empty()){
            int  node = q.front() ; q.pop();

            vis++;

            ans.push_back(node);

            cout<<"node ->" << node<<endl;

            for( int child : adj[node]){
                ind[child]--;

                if(ind[child] == 0) q.push(child);
            }
        }



        return ans.size() == k ? ans : vector<int>();

    };

    public:
        vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

            // int rs = rowConditions.size() , cs = colConditions.size();

            vector<vector<int>> ans(k , vector<int>(k , 0)) , rowAdj(k+1) , colAdj(k+1);

            unordered_map<int , int> rowInd , colInd;

            for (int i = 1; i <= k; ++i) {
                rowInd[i] = 0;
                colInd[i] = 0;
            }

            for( auto& it : rowConditions){
                rowAdj[it[0]].push_back(it[1]);
                rowInd[it[1]]++;
            }

            for( auto& it : colConditions){
                colAdj[it[0]].push_back(it[1]);
                colInd[it[1]]++;
            }

            cout<<"hey<<endl;";

            vector<int> rowTopo = topoSort(rowInd , rowAdj , k) , colTopo = topoSort(colInd , colAdj , k);

            if(rowTopo.size() == 0 || colTopo.size() == 0) return vector<vector<int>>();

            for(int i = 0 ; i < k ; ++i){
                ans[i][0] = rowTopo[i];

            }

            unordered_map<int , int> colTopoIndex ;

            for(int i = 0 ; i < k ; ++i){
                colTopoIndex[colTopo[i]] = i;
            }


            for(int i = 0 ; i < k ; ++i){
               int ele = ans[i][0] , pos = colTopoIndex[ele];
                ans[i][0] = 0;
               ans[i][pos] = ele;


            }


            return ans;


        }
    };

    void printMatrix(const vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            cout << "[]" << endl;
            return;
        }
        for (auto& row : matrix) {
            for (int val : row) cout << val << " ";
            cout << "\n";
        }
    }

    int main() {
        Solution sol;

        int k1 = 3;
        vector<vector<int>> row1 = {{1,2},{3,2}};
        vector<vector<int>> col1 = {{2,1},{3,2}};
        cout << "Test Case 1:\n";
        printMatrix(sol.buildMatrix(k1, row1, col1));

        int k2 = 3;
        vector<vector<int>> row2 = {{1,2},{2,3},{3,1},{2,3}};
        vector<vector<int>> col2 = {{2,1}};
        cout << "\nTest Case 2:\n";
        printMatrix(sol.buildMatrix(k2, row2, col2));

        return 0;
    }