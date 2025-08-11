class Solution {
public:
    vector<int> dy = {-1, 0, 1, 0};
    vector<int> dx = {0, 1, 0, -1};
    const int DIR = 4;

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int y, int x, int m, int n){
        visited[y][x] = 1;
        
        for(int i=0; i<DIR; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            if(grid[ny][nx] == '1' && !visited[ny][nx]){
                dfs(grid, visited, ny, nx, m, n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));

        // 끊어진 곳이 있을 수도 있으므로
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, visited, i, j, m, n);
                    count++;
                }
            }
        }

        return count;
    }
};