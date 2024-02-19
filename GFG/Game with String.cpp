class Solution{
public:
    int minValue(string s, int k){
        // code here
        int ans = 0;
        unordered_map<char,int> mp;
        priority_queue<int> pq;
        for(auto &i : s) mp[i]++;
        for(auto &i : mp) pq.push(i.second);
        while(k--) {
            int top = pq.top();
            pq.pop();
            pq.push(top - 1);
        }
        while(!pq.empty()) {
            int top = pq.top();
            pq.pop();
            ans += (top * top);
        }
        return ans;
    }
};