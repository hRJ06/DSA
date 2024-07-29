// User function template for C++

class Solution {
  private:
    vector<string> ans;
    bool valid(int i,int j, int n, vector<vector<int>> &mat) {
        if(i < 0 or i >= n or j < 0 or j >= n or !mat[i][j]) return false;
        return true;
    }
    void f(int i,int j, int n, vector<vector<int>> &mat, string &s) {
        if(i >= n - 1 and j >= n - 1) {
            ans.push_back(s);
            return;
        }
        mat[i][j] = 0;
        if(valid(i - 1, j, n, mat)) {
            s.push_back('U');
            f(i - 1, j, n, mat, s);
            s.pop_back();
        }
        if(valid(i + 1, j, n, mat)) {
            s.push_back('D');
            f(i + 1, j, n, mat, s);
            s.pop_back();
        }
        if(valid(i, j - 1, n, mat)) {
            s.push_back('L');
            f(i, j - 1, n, mat, s);
            s.pop_back();
        }
        if(valid(i, j + 1, n, mat)) {
            s.push_back('R');
            f(i, j + 1, n, mat, s);
            s.pop_back();
        }
        mat[i][j] = 1;
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        if(!mat[0][0]) return ans;
        string store = "";
        int n = mat.size();
        f(0, 0, n, mat, store);
        return ans;
    }
};