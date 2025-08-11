class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        vector<int> dx = {-1,-1,-1, 0,0, 1,1,1};
        vector<int> dy = {-1, 0, 1,-1,1,-1,0,1};
        const int DIRS = 8;

        vector<vector<int>> dist(n, vector<int>(n, 0));

        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;

        while(!q.empty()){
            auto [y, x] = q.front(); q.pop();

            if(y == n-1 && x == n-1) return dist[n-1][n-1];

            for(int i=0; i<DIRS; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

                if(grid[ny][nx] == 0 && dist[ny][nx] == 0){
                    q.push({ny, nx});
                    dist[ny][nx] = dist[y][x] + 1;
                }
            }          
        }

        return dist[n-1][n-1] ? dist[n-1][n-1] : -1;
    }
};