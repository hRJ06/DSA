class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(auto &i : arr) mp[i]++;
        for(auto &i : mp) pq.push({i.second,i.first});
        while(k) {
            auto top = pq.top();
            pq.pop();
            if(k >= top.first) k -= top.first;
            else {
                pq.push({top.first - k,top.second});
                break;
            }
        }
        return pq.size();
    }
};