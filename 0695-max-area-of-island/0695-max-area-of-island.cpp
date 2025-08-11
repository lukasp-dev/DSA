class Solution {
public:
    vector<int> dy = {-1, 0, 1, 0};
    vector<int> dx = {0, -1, 0, 1};
    const int DIR = 4;

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int y, int x, int m, int n){
        visited[y][x] = 1;
        int area = 1;

        for(int i=0; i<DIR; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue; 
            if(grid[ny][nx] == 1 && visited[ny][nx] == 0){
                area += dfs(grid, visited, ny, nx, m, n);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_area = 0;
        
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    max_area = max(max_area, dfs(grid, visited, i, j, m, n));
                }
            }
        }

        return max_area;
    }
};