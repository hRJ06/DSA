class Solution {
private:
    int helper(vector<int> &height,int m) {
        stack<int> s;
        int area = 0;
        for(int i = 0; i<=m; i++) {
            while(!s.empty() and (i == m or height[s.top()] >= height[i])) {
                int h = height[s.top()];
                s.pop();
                int w;
                if(s.empty())
                    w = i;
                else 
                    w = i - s.top() - 1;
                area = max(area,h * w);
            }
            s.push(i);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<int> height(m,0);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            int area = helper(height,m);
            ans = max(ans,area);
        }
        return ans;
    }
};