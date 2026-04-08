class Solution {
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};

public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int y, int x, int m, int n){
        visited[y][x] = 1;

        for(int i=0; i<4; ++i){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx] || grid[ny][nx] == '0') continue;
            dfs(grid, visited, ny, nx, m, n);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, visited, i, j, m, n);
                    ++count;
                }
            }
        }

        return count;
    }
};