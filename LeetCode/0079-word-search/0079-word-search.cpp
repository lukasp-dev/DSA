class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    bool findWord(vector<vector<char>>& board, string& word, vector<vector<int>>& visited, string& str, int y, int x, int m, int n) {
        if (str.size() == word.size()) {
            return str == word;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!visited[ny][nx]) {
                visited[ny][nx] = 1;
                str.push_back(board[ny][nx]);

                if (findWord(board, word, visited, str, ny, nx, m, n)) {
                    return true;
                }

                str.pop_back();
                visited[ny][nx] = 0;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> visited(m, vector<int>(n, 0));
                    string str = "";
                    str.push_back(board[i][j]);
                    visited[i][j] = 1;

                    if (findWord(board, word, visited, str, i, j, m, n)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
