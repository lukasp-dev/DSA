class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dy = {-1, 0, 1, 0};
        vector<int> dx = {0, -1, 0, 1};

        queue<pair<int, int>> q;
        int fresh = 0;
        int steps = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int curr = grid[i][j];

                switch(curr) {
                    case 0:
                        continue;
                        break;
                    case 1:
                        fresh++;
                        break;
                    case 2:
                        q.push({i, j});
                    default:
                        break;
                }
            }
        }

        if (fresh == 0) return 0;

        while(!q.empty() && fresh > 0) {
            int layer_size = q.size();

            for(int k = 0; k < layer_size; k++) {
                auto [curr_y, curr_x] = q.front(); q.pop();

                for(int i=0; i<4; i++) {
                    int next_y = curr_y + dy[i];
                    int next_x = curr_x + dx[i];
                    
                    if(next_y < 0 || next_y >= m || next_x < 0 || next_x >= n) continue;
                    
                    if(grid[next_y][next_x] != 1) continue;
                    
                    fresh--;
                    grid[next_y][next_x] = 2;
                    q.push({next_y, next_x});
                }
            }

            steps++;
        }

        return fresh ? -1 : steps;
    }
};