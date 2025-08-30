class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool r[9][9] = {false};
        bool c[9][9] = {false};
        bool box[9][9] = {false};
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] != '.') {
                    int val = board[i][j] - '1';
                    int b = (i / 3) * 3 + (j / 3);
                    if(r[i][val] or c[j][val] or box[b][val]) return false;
                    r[i][val] = c[j][val] = box[b][val] = true;
                }
            } 
        }
        return true;
    }
};