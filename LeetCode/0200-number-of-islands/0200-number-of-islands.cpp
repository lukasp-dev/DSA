class Solution {
public:

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int n, int m, int y, int x, vector<int>& dy, vector<int>& dx){
        visited[y][x] = 1;

        for(int i=0; i<4; i++){
            int ny = y + dy[i]; int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(visited[ny][nx]) continue;
            if(grid[ny][nx] == '0') continue;

            dfs(grid, visited, n, m, ny, nx, dy, dx);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> visited(n, vector(m, 0));
        vector<int> dy = {-1, 0, 1, 0};
        vector<int> dx = {0, -1, 0, 1};

        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, visited, n, m, i, j, dy, dx);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};