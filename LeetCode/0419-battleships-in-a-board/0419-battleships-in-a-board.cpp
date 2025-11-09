class Solution {
public:
    const vector<int> dy = {-1, 0, 1, 0};
    const vector<int> dx = {0, -1, 0, 1};

    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int n, int m, int y, int x){
        visited[y][x] = 1;
        for(int i=0; i<4; i++){
            int ny = y + dy[i], nx = x + dx[i];

            if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;

            if(!visited[ny][nx] && board[ny][nx] == 'X'){
                dfs(board, visited, n, m, ny, nx);
            } 
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(); 
        int m = board[0].size();
        int cnt = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && board[i][j] == 'X'){  
                    dfs(board, visited, n, m, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};