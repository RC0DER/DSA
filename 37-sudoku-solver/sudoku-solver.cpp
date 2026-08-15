class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        for(int i=0; i<9; i++){
            if(board[row][i] == dig) return false;
        }
        for(int i=0; i<9; i++){
            if(board[i][col] == dig) return false;
        }
        int srow = (row/3)*3;
        int scol = (col/3)*3;
        for(int r = 0; r<3; r++){
            for(int c = 0; c<3; c++){
                if(board[srow+r][scol+c] == dig) return false; 
            }
        }
        return true;
    }
    bool sudoku(vector<vector<char>>& board, int row, int col){
        if(row == 9){
            return true;
        }
        int nrow = row;
        int ncol = col+1;
        if(ncol == 9){
            nrow = row+1;
            ncol = 0;
        }
        if(board[row][col] != '.'){
            return sudoku(board, nrow, ncol);
        }
        for(char i='1'; i<='9'; i++){
            if(isSafe(board, row, col, i)){
                board[row][col] = i;
                if(sudoku(board, nrow, ncol)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    bool solveSudoku(vector<vector<char>>& board) {
        int r = 0;
        int c = 0;
        return sudoku(board, r, c);
    }
};