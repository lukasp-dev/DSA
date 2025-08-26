class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    const int dir = 4;

    bool find(int y, int x, vector<vector<int>>& visited, vector<vector<char>>& board, string& word, int depth, int m, int n){
        if(depth == word.size()-1) return true;

        for(int i=0; i<dir; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx]) continue;
            if (board[ny][nx] == word[depth + 1]) {
                visited[ny][nx] = 1;
                if (find(ny, nx, visited, board, word, depth + 1, m, n)) {
                    return true;
                }
                visited[ny][nx] = 0;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        char startChar = word[0];

        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == startChar){
                    visited[i][j] = 1;
                    if(find(i, j, visited, board, word, 0, m, n)){
                        return true;
                    }
                    visited[i][j] = 0;
                }
            }
        }

        return false;
    }
};