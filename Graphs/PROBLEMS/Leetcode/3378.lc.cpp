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
private:
int gcd(int a, int b) {
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(int a, int b) {
    return 1LL * a * b / gcd(a, b);  // Use 1LL to avoid overflow
}

public:
    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size() , componentCount = 0;

        sort(nums.begin(), nums.end());

        while (!nums.empty() && nums.back() > threshold) {
            componentCount++;
            nums.pop_back();
        }

        if (nums.empty()) return componentCount;


        DisjointSet ds(n);


        unordered_map <int , int> divisorMap;

       for (int i = 0; i < n; i++) {

            if(nums[i] > threshold) continue;

            for (int divisor = 1; divisor * divisor <= nums[i]; divisor++) {
                if (nums[i] % divisor == 0) {
                    if (divisorMap.count(divisor)) {
                        int otherIdx = divisorMap[divisor];
                        if (lcm(nums[i], nums[otherIdx]) <= threshold) {
                            ds.unionOfNodes(i, otherIdx);
                        }
                    } else {
                        divisorMap[divisor] = i;
                    }

                    int quotient = nums[i] / divisor;
                    if (quotient != divisor) {
                        if (divisorMap.count(quotient)) {
                            int otherIdx = divisorMap[quotient];
                            if (lcm(nums[i], nums[otherIdx]) <= threshold) {
                                ds.unionOfNodes(i, otherIdx);
                            }
                        } else {
                            divisorMap[quotient] = i;
                        }
                    }
                }
            }
        }

        unordered_set <int> parents;

         for(int i = 0 ; i < n ; ++i){
            parents.emplace(ds.findUltimateParent(i));
         };

         return  componentCount + parents.size();

    }
};

int main(){

    return 0;
}