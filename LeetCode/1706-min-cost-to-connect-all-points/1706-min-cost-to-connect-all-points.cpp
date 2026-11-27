class DSU {
private:
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n): parent(n), size(n, 1) {
       iota(parent.begin(), parent.end(), 0);
    }

    int find(int x){
        if(x == parent[x]) {
            return x;
        }
        
        parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int a, int b){
        int root_a = find(a);
        int root_b = find(b);
        
        if(root_a == root_b) {
            return false;
        }

        if(size[root_a] < size[root_b]){
            swap(root_a, root_b);
        }

        parent[root_b] = root_a;
        size[root_a] += size[root_b];

        return true;
    }
};

class Solution {
private:
    void makeCombi(vector<vector<int>>& points, 
                vector<tuple<int, int, int>>& weights, // 1. Fixed type & added '&'
                int k, int n, vector<int>& vec, int start) {
        
        if (vec.size() == k) {
            vector<int>& point_a = points[vec[0]];
            vector<int>& point_b = points[vec[1]];
            int manhattan = abs(point_b[0] - point_a[0]) + abs(point_b[1] - point_a[1]);
            
            weights.emplace_back(manhattan, vec[0], vec[1]);
            return; // 4. Stop recursion once combination size is reached
        }

        // 3. Use 'i < n' for 0-based indexing (assuming initial start = -1)
        for (int i = start + 1; i < n; i++) {
            vec.push_back(i);
            makeCombi(points, weights, k, n, vec, i); // 2. Added 'weights'
            vec.pop_back();
        }
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> vec;
        vector<tuple<int, int, int>> weights;
        int n = points.size();

        makeCombi(points, weights, 2, n, vec, -1);

        sort(weights.begin(), weights.end());

        DSU dsu(n);
        int ret = 0;

        for(tuple<int, int, int>& weight : weights) {
            auto& [w, u, v] = weight;
            if(dsu.unite(u, v)){
                ret += w;
            }
        }

        return ret;
    }
};