class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size(), freshOrange = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(i, j));
                }else if(grid[i][j] == 1){
                    freshOrange++;
                }
            }
        }

        int minute = 0;
        vector<int> dy = {-1, 0, 1, 0};
        vector<int> dx = {0, 1, 0, -1};

        while(!q.empty()){
            int neiNum = q.size();
            bool rottenedAnyInThisLevel = false;

            for(int i=0; i<neiNum; i++){
                auto [currY, currX] = q.front(); q.pop();
                
                for(int i=0; i<4; i++){
                    int ny = currY + dy[i];
                    int nx = currX + dx[i];

                    if(ny < 0 || ny>=n || nx < 0 || nx >= m || grid[ny][nx] == 0 || grid[ny][nx] == 2) continue;
                    grid[ny][nx] = 2;
                    freshOrange--;
                    rottenedAnyInThisLevel = true;
                    q.push(make_pair(ny, nx));
                }
            }

            if(rottenedAnyInThisLevel) minute++;
        }

        return freshOrange ? -1 : minute;
    }
};