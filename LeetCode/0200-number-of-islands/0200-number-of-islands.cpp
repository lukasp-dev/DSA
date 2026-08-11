class Solution {
private:
    const vector<int> dy = {0, -1, 0, 1};
    const vector<int> dx = {-1, 0, 1, 0};
    int n;
    int m;

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int y, int x) {
        visited[y][x] = true;
        queue<pair<int, int>> q;
        q.push({y, x});
        
        while(!q.empty()) {
            int currLevelNumber = q.size();

            for(int i=0; i<currLevelNumber; ++i) {
                auto [currY, currX] = q.front(); q.pop();

                for(int j=0; j<4; j++) {
                    int ny = currY + dy[j];
                    int nx = currX + dx[j];

                    if(ny<0 || ny>=n || nx < 0 || nx>=m || visited[ny][nx] || grid[ny][nx] == '0') continue;

                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
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
                    bfs(grid, visited, i, j);
                    numbers++;
                }
            }
        }

        return numbers;
    }
};