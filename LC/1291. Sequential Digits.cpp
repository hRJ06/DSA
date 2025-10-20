class Solution {
private:
    vector<int> ans;
    void dfs(int low,int high,int i,int n) {
        if(n >= low and n <= high) ans.push_back(n);
        if(n > high or i > 9) return;
        dfs(low,high,i + 1,n * 10 + i);
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        for(int i = 1; i<=9; i++)
            dfs(low,high,i,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};