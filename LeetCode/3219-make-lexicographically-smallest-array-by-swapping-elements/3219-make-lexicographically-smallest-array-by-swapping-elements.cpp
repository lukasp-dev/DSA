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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<vector<int>> num_to_indices;
        vector<int> ret(n);
        for(int i=0; i<n; i++) {
            num_to_indices.push_back({nums[i], i});
        }

        sort(num_to_indices.begin(), num_to_indices.end());
    
        DSU dsu(n);
        for (int i = 1; i < n; ++i) {
            const auto& prev = num_to_indices[i - 1];
            const auto& curr = num_to_indices[i];

            if (curr[0] - prev[0] <= limit) {
                dsu.unite(prev[1], curr[1]);
            }
        }

        unordered_map<int, vector<int>> group_values;
        unordered_map<int, vector<int>> group_indices;

        for(int i=0; i<num_to_indices.size(); i++){
            int num = num_to_indices[i][0];
            int idx = num_to_indices[i][1];
            int key = dsu.find(idx);

            group_values[key].push_back(num);
            group_indices[key].push_back(idx);
        }

        for(auto& [root, indices] : group_indices) {
            sort(indices.begin(), indices.end());
            int i = 0;

            for(int idx : indices) {
                ret[idx] = group_values[root][i];
                ++i;
            }
        }

        return ret;
    }
};

/*
1. Iterate the original array, form the unordered_map<int, vector<int>> (num -> indices)
2. sort the original array, do the union-find unite the vertex if (num_2 - num_1 <= k)
3. 
*/