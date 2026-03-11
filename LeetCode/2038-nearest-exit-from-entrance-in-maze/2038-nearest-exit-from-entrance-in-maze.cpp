class Solution {
public:
    vector<int> dy = {-1, 0, 1, 0};
    vector<int> dx = {0, -1, 0, 1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        queue<pair<int, int>> q;
        
        q.push({entrance[0], entrance[1]});
        // Using the maze itself as a 'visited' set to save space
        maze[entrance[0]][entrance[1]] = '+';

        int distance = 0;

        while(!q.empty()){
            int numNodesAtLevel = q.size();
            for(int i = 0; i < numNodesAtLevel; i++){
                auto [currY, currX] = q.front(); q.pop();

                for(int j = 0; j < 4; j++){
                    int ny = currY + dy[j];
                    int nx = currX + dx[j];

                    // 1. Check bounds and if the path is open
                    if(ny >= 0 && ny < n && nx >= 0 && nx < m && maze[ny][nx] == '.'){
                        
                        // 2. Check if this NEW cell is an exit
                        if(ny == 0 || ny == n-1 || nx == 0 || nx == m-1) {
                            return distance + 1;
                        }

                        // 3. Mark as visited immediately before pushing to queue
                        maze[ny][nx] = '+';
                        q.push({ny, nx});
                    }
                }
            }
            distance++;
        }
        return -1;
    }
};