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