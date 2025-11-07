class Solution {
public:
    const vector<int> dy = {-1, 0, 1, 0};
    const vector<int> dx = {0, -1, 0, 1};

    void dfs(int m, int n, vector<vector<char>>& grid, vector<vector<int>>& visited, int y, int x){
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny>=m || nx < 0 || nx >=n) continue;

            if(visited[ny][nx] == 0 && grid[ny][nx] == '1'){
                visited[ny][nx] = 1;
                dfs(m, n, grid, visited, ny, nx);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    dfs(m, n, grid, visited, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};