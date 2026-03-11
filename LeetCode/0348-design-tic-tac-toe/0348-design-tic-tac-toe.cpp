class TicTacToe {
public:
    vector<int> rows, cols;
    int diagonal, antiDiagonal;
    int n;

    TicTacToe(int n) {
        this->rows = vector<int>(n, 0);
        this->cols = vector<int>(n, 0);
        this->diagonal = 0;
        this->antiDiagonal = 0;
        this->n = n;
    }
    
    int move(int row, int col, int player) {
        // player 1 => +1, player 2 => -1
        int val = player == 1 ? 1 : -1;
        
        rows[row] += val;
        cols[col] += val;

        if(row == col){ // diagonal => row == col
            diagonal += val;
        }
        
        if(row + col == n - 1){ // antiDiagonal => row + col == n - 1
            antiDiagonal += val;
        }

        if (abs(rows[row]) == n || 
            abs(cols[col]) == n || 
            abs(diagonal) == n || 
            abs(antiDiagonal) == n) {
            return player;
        }

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */