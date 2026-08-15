class Solution {
public:
    bool isSafe(vector<string> &board, int r, int c, int n){
        // check column for placing Q
        for(int i=0; i<n; i++){
            if(board[r][i] == 'Q') return false;
        }
        // check row for placing Q
        for(int i=0; i<n; i++){
            if(board[i][c] == 'Q') return false;
        }
        // check for left diagonal
        for(int i=r, j=c; i>=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        // check for right diagonal
        for(int i=r, j=c; i>=0 && j<n; i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void nQueen(vector<string> &board, int row, int n, vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int j=0; j<n; j++){
            if(isSafe(board, row, j, n)){
                board[row][j] = 'Q';
                nQueen(board, row+1, n, ans);
                board[row][j] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> ans;
        int row =0;
        nQueen(board, row, n, ans);
        return ans;
    }
};