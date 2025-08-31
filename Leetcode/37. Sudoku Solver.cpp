class Solution {
private:
    bool check(vector<vector<char>> &board, int r, int c, char ch) {
        for(int i = 0; i<9; i++) {
            if(board[r][i] == ch or board[i][c] == ch) return false;
        }
        int bR = (r / 3) * 3;
        int bC = (c / 3) * 3;
        for(int i = 0; i<3; i++) {
            for(int j = 0; j<3; j++) {
                if(board[bR + i][bC + j] == ch) return false;
            }
        }
        return true;
    }
    bool f(vector<vector<char>> &board) {
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] != '.') continue;
                for(char c = '1'; c<='9'; c++) {
                    if(check(board, i, j, c)) {
                        board[i][j] = c;
                        if(f(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};