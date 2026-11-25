class Solution {
private:
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, -1, 0, 1};

void dfs(vector<pair<int, int>>& island, vector<vector<int>>& grid, vector<vector<bool>>& visited, int y, int x, int n, int m) {
    island.push_back({y, x});
    visited[y][x] = true;

    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || grid[ny][nx] == 0 || visited[ny][nx]) continue;
        dfs(island, grid, visited, ny, nx, n, m);
    }
}

public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<pair<int, int>>> islands;
        set<vector<pair<int, int>>> unique_islands;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> island;
                    dfs(island, grid, visited, i, j, n, m);
                    islands.push_back(island);
                }
            }
        }

        for(vector<pair<int, int>>& island : islands){
            sort(island.begin(), island.end());
            auto [y_0, x_0] = island[0];
            for(auto& [y, x] : island) {
                y -= y_0;
                x -= x_0;
            }

            unique_islands.insert(island);
        }

        return unique_islands.size();
    }
};