class Solution {
public:
    pair<bool, bool> check(int y, int x, int size, vector<vector<int>>& grid) {
        if (size == 1) return {true, true};
        bool isSame = true;
        int cmp = grid[y][x];

        for (int i = y; i < y + size; i++) {
            for (int j = x; j < x + size; j++) {
                if (grid[i][j] != cmp) {
                    isSame = false;
                    break;
                }
            }
            if (!isSame) break;
        }
        return {false, isSame};
    }

    Node* go(vector<vector<int>>& grid, int y, int x, int size) {
        auto [isLeaf, isSame] = check(y, x, size, grid);

        if (isSame) {
            return new Node(grid[y][x] == 1, true);
        }

        Node* node = new Node();
        node->isLeaf = false;

        node->topLeft = go(grid, y, x, size / 2);
        node->topRight = go(grid, y, x + size / 2, size / 2);
        node->bottomLeft = go(grid, y + size / 2, x, size / 2);
        node->bottomRight = go(grid, y + size / 2, x + size / 2, size / 2);

        return node;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return go(grid, 0, 0, n);
    }
};
