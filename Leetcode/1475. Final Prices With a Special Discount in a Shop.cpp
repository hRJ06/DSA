class Solution {
private:
    vector<int> f(vector<int> &prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for(int i = n - 1; i>=0; i--) {
            while(s.top() != -1 and prices[s.top()] > prices[i])
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> v = f(prices);
        int n = prices.size();
        vector<int> ans;
        for(int i = 0; i<n; i++) {
            int price = prices[i];
            if(v[i] != -1) price -= prices[v[i]];
            ans.push_back(price);
        }
        return ans;
    }
};