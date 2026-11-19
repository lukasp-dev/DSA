class TicTacToe {
vector<int> rowCounts;
vector<int> columnCounts;
int rightDiagonal;
int leftDiagonal;
int n;

public:
    TicTacToe(int n): n(n), rowCounts(n, 0), columnCounts(n, 0), rightDiagonal(0), leftDiagonal(0) {
        
    }
    
    int move(int row, int col, int player) {
        int p = player == 1 ? 1 : -1;

        rowCounts[row] += p;
        columnCounts[col] += p;

        if(row == col) {
            rightDiagonal += p;
        }

        if(row + col == n-1) {
            leftDiagonal += p;
        }

        if (abs(rowCounts[row]) == n ||
            abs(columnCounts[col]) == n ||
            abs(rightDiagonal)== n ||
            abs(leftDiagonal) == n) {
                return player;
            }
        
        cout << leftDiagonal << "\n";

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */