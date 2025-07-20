class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9); // i로 잡고
        vector<set<char>> columns(9); // j로 잡고
        vector<set<char>> boxes(9);

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                char val = board[i][j];
                if(val == '.') continue;

                if(rows[i].find(val) == rows[i].end()){
                    rows[i].insert(val);
                }else{
                    return false;
                }

                if(columns[j].find(val) == columns[j].end()){
                    columns[j].insert(val);
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