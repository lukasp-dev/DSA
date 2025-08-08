class Solution {
public:
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {-1, 0, 1, 0};

    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int y, int x, int m, int n){
        queue<pair<int, int>> q;
        q.push({y, x});

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                pair<int, int> curr = q.front(); q.pop();

                for(int i=0; i<4; i++){
                    int ny = curr.first + dy[i];
                    int nx = curr.second + dx[i];

                    if(ny < 0 || ny >=m || nx < 0 || nx >= n) continue;
                    if(!visited[ny][nx] && grid[ny][nx] == '1'){
                        visited[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    visited[i][j] = 1;
                    bfs(grid, visited, i, j, m, n);
                    count++;
                }
            }
        }

        return count;
    }
};