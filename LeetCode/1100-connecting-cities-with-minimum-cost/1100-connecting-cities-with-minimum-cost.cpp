class DSU {
private:
    vector<int> size;
    vector<int> parent;
public:
    DSU(int n) : size(n, 1), parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(x == parent[x]) {
            return x;
        }

        parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);

        if(root_a == root_b) {
            return false;
        }

        if(size[root_a] < size[root_b]) {
            swap(root_a, root_b);
        }
        
        parent[root_b] = root_a;
        size[root_a] += size[root_b];

        return true;
    }
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<tuple<int, int, int>> weights;
        for(vector<int>& connection : connections) {
            int u = connection[0], v = connection[1], w = connection[2];

            weights.emplace_back(w, u, v);
        }

        sort(weights.begin(), weights.end());
        int target_count = n - 1;
        int min_cost = 0;
        
        DSU dsu(n+1);

        for(tuple<int, int, int>& wei : weights) {
            auto& [w, u, v] = wei;

            if(dsu.unite(u, v)){
                --target_count;
                min_cost += w;
            }
        }

        return target_count == 0 ? min_cost : -1;
    }
};