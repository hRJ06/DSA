class Solution {
    private:
        bool f(int index, int n, vector<int> &ans, vector<bool> &v) {
            if(index >= ans.size()) return true;
            if(ans[index] != -1) return f(index + 1, n, ans, v);
            for(int num = n; num>=1; num--) {
                if(v[num]) continue;
                v[num] = true;
                ans[index] = num;
                if(num != 1) {
                    int j = num + index;
                    if(j < ans.size() and ans[j] == -1) {
                        ans[j] = num;
                        if(f(index + 1, n, ans, v)) return true;
                        ans[j] = -1;
                    }
                }
                else 
                    if(f(index + 1, n, ans, v)) return true;
                v[num] = false;
                ans[index] = -1;
            }
            return false;
        }
    public:
        vector<int> constructDistancedSequence(int n) {
            vector<int> ans(2 * n - 1, -1);
            vector<bool> v(n, false);
            f(0, n, ans, v);
            return ans;
        }
    };