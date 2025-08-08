class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int y, int x, int n, int m){
        visited[y][x] = 1;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(!visited[ny][nx] && grid[ny][nx] == '1') dfs(grid, visited, ny, nx, n, m);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, visited, i, j, n, m);
                    count++;
                }
            }
        }

        return count;
    }
};