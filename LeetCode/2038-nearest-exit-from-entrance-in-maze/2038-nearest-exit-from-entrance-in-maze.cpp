class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int dy[] = {-1, 0, 1, 0};
        int dx[] = {0, -1, 0, 1};

        int n = maze.size(), m = maze[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<vector<int>> q;
        visited[entrance[0]][entrance[1]] = 1;
        entrance.push_back(0);
        q.push(entrance);

        while(!q.empty()){
            vector<int> curr = q.front(); q.pop();
            int currDist = curr[2];
            int currY = curr[0], currX = curr[1];
           if ((currY == 0 || currY == n-1 || currX == 0 || currX == m-1) 
                && !(currY == entrance[0] && currX == entrance[1])) {
                return currDist;
            }


            for(int i=0; i<4; i++){
                int ny = currY + dy[i], nx = currX + dx[i];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

                if(!visited[ny][nx] && maze[ny][nx] == '.'){
                    q.push({ny, nx, currDist+1});
                    visited[ny][nx] = 1;
                }
            }
        }

        return -1;
    }
};