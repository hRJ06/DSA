class Solution {
private:
    bool dfs(int r,int c,int n,int m,vector<vector<char>> &board,string &word,int i) {
        if(i == word.size()) return true;
        if(r < 0 or r == n or c < 0 or c == m or board[r][c] != word[i]) return false;
        board[r][c] = '0';
        bool up = dfs(r - 1,c,n,m,board,word,i + 1);
        bool down = dfs(r + 1,c,n,m,board,word,i + 1);
        bool left = dfs(r,c - 1,n,m,board,word,i + 1);
        bool right = dfs(r,c + 1,n,m,board,word,i + 1);
        board[r][c] = word[i];
        return up or down or left or right;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(board[i][j] == word[0])
                    if(dfs(i,j,n,m,board,word,0))
                        return true;
            }
        }
        return false;
    }
};