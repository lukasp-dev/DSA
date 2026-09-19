class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9];
        unordered_set<int> cols[9];
        unordered_set<int> boxes[9];

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                int val = board[i][j];

                if(val == '.') continue;

                if(rows[i].count(val)) return false;
                rows[i].insert(val);
                
                if(cols[j].count(val)) return false;
                cols[j].insert(val);

                int index = (i/3)*3 + (j/3); 
                if(boxes[index].count(val)) return false;
                boxes[index].insert(val);
            }
        }

        return true;
    }
};