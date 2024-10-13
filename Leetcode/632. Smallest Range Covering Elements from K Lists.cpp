class cmp {
public:
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, cmp> pq;
        int n = nums.size();
        int a = INT_MAX, b = INT_MIN;
        for(int i = 0; i<n; i++) {
            pq.push({nums[i][0], {i, 0}});      
            a = min(a, nums[i][0]);
            b = max(b, nums[i][0]);
        }
        int start = a, end = b;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int r = top.second.first, c = top.second.second;
            if(c + 1 < nums[r].size()) {
                int ele = nums[r][c + 1];
                pq.push({ele, {r, c + 1}});
                b = max(b, ele);
                if(b - pq.top().first < end - start) {
                    end = b;
                    start = pq.top().first;
                }
            }
            else {
                break;
            }
        }
        return {start, end};
    }
};