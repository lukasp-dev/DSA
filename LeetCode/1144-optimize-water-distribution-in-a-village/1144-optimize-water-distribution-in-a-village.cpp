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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        int cost = 0;
        map<pair<int, int>, int> lookup;
    
        for(vector<int>& pipe : pipes) {
            int u = pipe[0];
            int v = pipe[1];
            int w = pipe[2];

            if(u > v) {
                swap(u, v);
            }

            pair<int, int> key = make_pair(u, v);
            if(lookup.count(key)) {
                if(lookup[key] > w) {
                    lookup[key] = w;
                } 
            } else {
                lookup[key] = w;
            }
        }

        vector<tuple<int, int, int>> weights;

        for (int house = 1; house <= n; ++house) {
            weights.emplace_back(wells[house - 1], 0, house);
        }

        for(auto& [key, val] : lookup) {
            int u = key.first, v = key.second;
            int w = val;
            weights.emplace_back(w, u, v);
        }

        sort(weights.begin(), weights.end());
        DSU dsu(n+1);

        for(tuple<int, int, int>& wei : weights) {
            int curr_cost = cost;
            auto& [w, u, v] = wei;

            if(dsu.unite(u, v)){
                cost += w;
            }
        }

        return cost;
    }
};