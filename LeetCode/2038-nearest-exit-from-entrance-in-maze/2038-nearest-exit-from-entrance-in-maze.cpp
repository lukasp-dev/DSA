class Solution {
public:
    const vector<int> dy = {-1, 0, 1, 0};
    const vector<int> dx = {0, 1, 0, -1}; 

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(); int m = maze[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));

        queue<vector<int>> q;
        visited[entrance[0]][entrance[1]] = 0;
        q.push(entrance);

        while(!q.empty()){
            int size = q.size();
                auto curr = q.front(); q.pop();
                int currY = curr[0], currX = curr[1];
                if ((currY == 0 || currY == n-1 || currX == 0 || currX == m-1) 
                && !(currY == entrance[0] && currX == entrance[1])) {
                    return visited[currY][currX];
                }

                for(int i=0; i<4; i++){
                    int ny = currY + dy[i];
                    int nx = currX + dx[i];

                    if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                    
                    if(visited[ny][nx]==-1&& maze[ny][nx] == '.'){
                        visited[ny][nx] = visited[currY][currX]+1;
                        q.push({ny, nx});
                    }
                }
        }
        return -1;
    }
};