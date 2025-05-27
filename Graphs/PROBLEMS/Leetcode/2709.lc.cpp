#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
    vector<int> parent , size;

    public:

    DisjointSet(int n){
        size.resize(n , 1);
        parent.resize(n);
        for(int i = 0 ; i < n ; ++i) parent[i] = i;
    }

    int findUltimateParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findUltimateParent(parent[u]);
    }

    void unionOfNodes(int u , int v){
        int U = findUltimateParent(u) , V = findUltimateParent(v);

        if(U == V) return;

        if(size[U] < size[V]){
            size[V] += size[U];
            parent[U] = V;
        }else{
            size[U] += size[V];
            parent[V] = U;
        }
    }
};

class Solution {
    private :

    public:
        bool canTraverseAllPairs(vector<int>& nums) {
            int n = nums.size();

            if (n == 1) return true;


            DisjointSet ds(n);

            auto getPrimesFactors = [](int a){
                unordered_set<int> primes ;
                int l = ceil(sqrt(a));

                for(int i = 2 ; i < l ; ++i){
                    while(a%i == 0){
                        primes.emplace(i);
                        a /= i;
                    }
                }

                    if(a > 1) primes.emplace(a); // prime number left hai bas
                    return primes;
            };

            unordered_map<int , int> primesMap;

            for(int i = 0 ; i < n ; ++i){
                int a = nums[i];
                auto primes = getPrimesFactors(a);

                for(auto& p : primes){

                    if(primesMap.count(p)){
                        ds.unionOfNodes(i , primesMap[p]);
                    }else primesMap[p] = i;
                }
            }

            int mainParent = ds.findUltimateParent(0);

            for(int i = 1 ; i < n ; ++i){
                if(ds.findUltimateParent(i) == mainParent) continue;
                return false;
            }

            return true;
        }
    };

int main(){

    return 0;
}