class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int r, int c, char dig){
        for(int i=0; i<9; i++){
            if(i==c) continue;
            else if(board[r][i] == dig) return false;
        }

        for(int i=0; i<9; i++){
            if(i==r) continue;
            else if(board[i][c] == dig) return false;
        }

        int srow = (r/3)*3;
        int scol = (c/3)*3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(srow+i==r && scol+j==c) continue;
                else if(board[srow+i][scol+j] == dig) return false;
            }
        }
        return true;
    }
    bool check(vector<vector<char>>& board, int r, int c){
        if(r == 9){
            return true;
        }int nextr = r;
        int nextc = c+1;
        if(nextc == 9){
            nextr = r+1;
            nextc = 0;
        }
        char dig = board[r][c];
        if(board[r][c] == '.'){
            return check(board, nextr, nextc);
        }
        else if(isSafe(board, r, c, dig)){
            return check(board, nextr, nextc);
        }
        else return false;

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return check(board, 0, 0);
    }
};