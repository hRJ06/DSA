class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> store = heights;
        sort(heights.begin(),heights.end());
        int ans = 0, n = heights.size();
        for(int i = 0; i<n; i++) 
            if(heights[i] != store[i]) ans++;
        return ans;   
    }
};