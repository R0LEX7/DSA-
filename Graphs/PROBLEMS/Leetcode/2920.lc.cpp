#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    private:
    vector<int> parent ,size;

    public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n , 1);

        for(int i = 0 ; i < n ; ++i) parent[i] = i;
    }


    int findUltimateParent(int u){
        if(u == parent[u]) return u;

        return parent[u] = findUltimateParent(parent[u]);
    }

    void resetUnion(int u){
        parent[u] = u;
    }

    void unionBySize(int u , int v){
        int U = findUltimateParent(u) , V = findUltimateParent(v);

        if(U == V) return ;

        if(size[U] < size[V]) {
            parent[U] = V;
            size[V] += size[U];
        }else{
            parent[V] = U;
            size[U] += size[V];
        }
    }
};



class Solution {
    private:
    static bool compare(vector<int> a , vector<int> b){
        return a[2]<b[2];
    }
    public:
        vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

            DisjointSet ds(n);

            ds.unionBySize(0 , firstPerson);



            vector<int> ans;
            // sorting
            sort(meetings.begin() , meetings.end() , compare);
            int ms = meetings.size();

            for(int i = 0 ; i < ms ;){
                vector<int> people ;

                int mt = meetings[i][2];

                while(i < ms && meetings[i][2] == mt ){
                    int u = meetings[i][0] , v =  meetings[i][1];
                    ds.unionBySize(u , v);
                    people.push_back(u);
                    people.push_back(v);
                    i++;
                }

                for(int p : people){
                    if(ds.findUltimateParent(p) == ds.findUltimateParent(0)) continue;
                    ds.resetUnion(p);
                }
            }

            for(int i = 0 ; i < n ; ++i){
                if(ds.findUltimateParent(i) != ds.findUltimateParent(0)) continue;

                ans.push_back(i);
            }

            return ans;
        }
    };
int main(){

    return 0;
}