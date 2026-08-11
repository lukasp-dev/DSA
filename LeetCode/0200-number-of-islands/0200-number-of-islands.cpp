class Solution {
private:
    const vector<int> dy = {0, -1, 0, 1};
    const vector<int> dx = {-1, 0, 1, 0};
    int n;
    int m;

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int y, int x){
        visited[y][x] = true;

        for(int i=0; i<4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || grid[ny][nx] == '0') continue;
            dfs(grid, visited, ny, nx);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(); m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int numbers = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, visited, i, j);
                    numbers++;
                }
            }
        }

        return numbers;
    }
};