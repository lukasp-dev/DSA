class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9);
        vector<set<char>> cols(9);
        vector<set<char>> boxes(9);

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char val = board[i][j];
                if(val == '.') continue;

                if(rows[i].find(val) == rows[i].end()){
                    rows[i].insert(val);
                }else{
                    return false;
                }

                if(cols[j].find(val) == cols[j].end()){
                    cols[j].insert(val);
                }else{
                    return false;
                }

                int index = (i/3)*3 + (j/3);
                if(boxes[index].find(val) == boxes[index].end()){
                    boxes[index].insert(val);
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};