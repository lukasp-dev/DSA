class Solution {
    vector<int> dy = {0, 1, 0, -1};
    vector<int> dx = {-1, 0, 1, 0};
    int n, m;

    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int y, int x) {
        queue<pair<int, int>> q;
        q.push({y, x});
        visited[y][x] = 1;

        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                int ny = curr.first + dy[i];
                int nx = curr.second + dx[i];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || grid[ny][nx]=='0') continue;

                q.push({ny, nx});
                visited[ny][nx] = 1;
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int total_num_of_islands = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(visited[i][j]) continue;

                if(grid[i][j] == '1') {
                    bfs(grid, visited, i, j);
                    total_num_of_islands++;
                }
            }
        }
        
        return total_num_of_islands;
    }
};