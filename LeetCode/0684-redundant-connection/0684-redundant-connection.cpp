class DSU {
private:
    vector<int> size;
    vector<int> parent;
public:
    DSU(int n): size(n, 1), parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(x == parent[x]) {
            return x;
        }

        parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int a, int b){
        int rootA = find(a);
        int rootB = find(b);

        if(rootA == rootB) {
            return false; 
        }

        if(size[rootA] < size[rootB]) {
            swap(rootA, rootB);
        }

        parent[rootB] = rootA;
        size[rootA] += size[rootB];

        return true;
    }
};

class Solution {

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);

        vector<int> ret;

        for(auto& edge : edges) {
            int a = edge[0], b = edge[1];
            if(dsu.find(a) == dsu.find(b)){
                ret = {a, b};
            }

            dsu.unite(a, b);
        }

        return ret;
    }
};