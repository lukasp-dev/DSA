class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n = board.size();

        unordered_map<int, set<char>> rows;
        unordered_map<int, set<char>> cols;
        unordered_map<int, set<char>> boxes;

        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                char val = board[i][j];

                if(val == '.') continue;

                if(rows[i].count(val)) return false;
                rows[i].insert(val);

                if(cols[j].count(val)) return false;
                cols[j].insert(val);

                int index = (i/3)*3 + j/3;
                if(boxes[index].count(val)) return false;
                boxes[index].insert(val);
            }
        }

        return true;
    }
};