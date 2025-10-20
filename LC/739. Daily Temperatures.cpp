class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> s;
        s.push(-1);
        for(int i = n - 1; i>=0; i--) {
            while(s.top() != -1 and arr[s.top()] <= arr[i])
                s.pop();
            if(s.top() != -1) ans[i] = s.top() - i;
            s.push(i);
        }
        return ans;
    }
};