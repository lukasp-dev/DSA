class Solution {
private:
    struct CoordHash {
        size_t operator()(const vector<int>& coord) const {
            size_t rowHash = hash<int>{}(coord[0]);
            size_t colHash = hash<int>{}(coord[1]);
            return rowHash ^ (colHash + 0x9e3779b9u + (rowHash << 6) + (rowHash >> 2));
        }
    };

    using ParentMap = unordered_map<vector<int>, vector<int>, CoordHash>;
    using SizeMap = unordered_map<vector<int>, int, CoordHash>;

    vector<int> dy = {-1, 0, 1, 0};
    vector<int> dx = {0, -1, 0, 1};

    vector<int> find(const vector<int>& X, ParentMap& parent,SizeMap& size) {
        if(X == parent[X]) {
            return X;
        }

        parent[X] = find(parent[X], parent, size);

        return parent[X];
    }

    bool unite(const vector<int>& A, const vector<int>& B, ParentMap& parent, SizeMap& size) {
        vector<int> rootA = find(A, parent, size);
        vector<int> rootB = find(B, parent, size);

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

public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        ParentMap parent;
        SizeMap size;
        vector<int> answer;
        int islandCount = 0;

        for (const auto& pos : positions) {
            if (parent.count(pos)) {
                answer.push_back(islandCount);
                continue;
            }

            parent[pos] = pos;
            size[pos] = 1;
            ++islandCount;

            int y = pos[0];
            int x = pos[1];

            for (int i = 0; i < 4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;

                vector<int> neighbor = {ny, nx};
                if (parent.count(neighbor) && unite(pos, neighbor, parent, size)) {
                    --islandCount;
                }
            }

            answer.push_back(islandCount);
        }
        return answer;
    }
};