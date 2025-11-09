class Solution {
public:
    const vector<int> dy = {-1, 0, 1, 0};
    const vector<int> dx = {0, -1, 0, 1}; 

    void bfs(vector<vector<char>>& board, vector<vector<int>>& visited, int n, int m, int y, int x){
        queue<pair<int, int>> q;
        q.push({y, x});
        
        while(!q.empty()){
            auto [currY, currX] = q.front(); q.pop();

            for(int i=0; i<4; i++){
                int ny = currY + dy[i];
                int nx = currX + dx[i];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if(!visited[ny][nx] && board[ny][nx] == 'X') {
                    visited[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }
        }

    }

    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int count = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && board[i][j] == 'X'){
                    visited[i][j] = 1;
                    bfs(board, visited, n, m, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};