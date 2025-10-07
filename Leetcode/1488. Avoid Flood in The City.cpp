typedef pair<int,int> p;
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, pair<int,vector<int>>> mp;
        unordered_map<int, bool> filled;
        int n = rains.size();
        for(int i = 0; i<n; i++) {
            mp[rains[i]].first = 0;
            mp[rains[i]].second.push_back(i);
        }
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> ans;
        for(int i = 0; i<n; i++) {
            if(rains[i] > 0) {
                if(filled[rains[i]]) return {};
                else {
                    int index = mp[rains[i]].first;
                    vector<int> all_days_rained_for_lake = mp[rains[i]].second;
                    if(index + 1 < all_days_rained_for_lake.size()) {
                        index++;
                        mp[rains[i]].first = index;
                        pq.push({all_days_rained_for_lake[index], rains[i]});
                    }
                    filled[rains[i]] = true;
                    ans.push_back(-1);
                }
            }
            else {
                if(pq.empty()) ans.push_back(1); /* Dry random lake */
                else {
                    p top = pq.top();
                    pq.pop();
                    int lake = top.second;
                    filled[lake] = false;
                    ans.push_back(lake);
                }
            }
        }
        return ans;
    }
};