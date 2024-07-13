class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, pair<int, pair<int,char>>>> v(n);
        for(int i = 0; i<n; i++) {
            v[i] = {positions[i], {i, {healths[i], directions[i]}}};
        }
        sort(v.begin(), v.end());
        stack<int> s;
        vector<int> ans(n, -1);
        for(int i = 0; i<n; i++) {
            int health = v[i].second.second.first;
            char direction = v[i].second.second.second;
            int index = v[i].second.first;
            if(direction != 'L') {
                // ->
                s.push(index);
                ans[index] = health;
            }
            else {
                int left_health_if_any = health;
                // <-
                while(!s.empty()) {
                    // ->
                    int opponent_index = s.top();
                    int opponent_health = ans[opponent_index];
                    if(opponent_health > left_health_if_any) {
                        ans[opponent_index]--;
                        left_health_if_any = -1;
                        break;
                    }
                    else if(opponent_health < left_health_if_any) {
                        ans[opponent_index] = -1;
                        left_health_if_any--;
                        s.pop();
                    }
                    else {
                        ans[opponent_index] = -1;
                        left_health_if_any = -1;
                        s.pop();
                        break;
                    }
                }
                ans[index] = left_health_if_any;
            }
        }
        vector<int> result;
        for(auto &i : ans)
            if(i > 0) result.push_back(i);
        return result;
    }
};
