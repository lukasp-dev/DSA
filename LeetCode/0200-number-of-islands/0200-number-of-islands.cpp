class Solution {
public:
    vector<int> dy;
    vector<int> dx;
    int m, n;

    Solution() {
        dy = {-1, 0, 1, 0};
        dx = {0, -1, 0, 1};
    }


    void bfs(vector<vector<int>>& visited, vector<vector<char>>& grid, int y, int x) {
        queue<pair<int, int>> q;
        q.push({y, x});
        visited[y][x] = 1;

        while(!q.empty()) {
            auto [currY, currX] = q.front(); q.pop();

            for(int i=0; i<4; i++) {
                int nextY = currY + dy[i];
                int nextX = currX + dx[i];

                if(nextY < 0 || nextY >= m || nextX < 0 || nextX >= n || grid[nextY][nextX] == '0' || visited[nextY][nextX]) continue;

                q.push({nextY, nextX});
                visited[nextY][nextX] = 1;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size();
        int ans = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0)); 

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '0' || visited[i][j]) continue;
                bfs(visited, grid, i, j);
                ans++;
            }
        }

        return ans;
    }
};