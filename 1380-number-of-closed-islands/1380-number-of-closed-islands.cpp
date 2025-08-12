class Solution {
public:
    vector<int> dy = {0, -1, 0, 1};
    vector<int> dx = {1, 0, -1, 0};
    const int DIR = 4;

    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int y, int x, int m, int n){
        visited[y][x] = 1;
        bool closed = true;
        if(y == 0 || x == 0 || y == m-1 || x == n-1) closed = false;
        
        for(int i=0; i<DIR; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;

            if(visited[ny][nx] == 0 && grid[ny][nx] == 0){
                if(!dfs(grid, visited, ny, nx, m, n)){
                    closed = false;
                }
            }
        }

        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] == 0 && grid[i][j] == 0){
                    if(dfs(grid, visited, i, j, m, n)){
                        count++;
                    }
                }
            }
        }

        return count; 
    }
};