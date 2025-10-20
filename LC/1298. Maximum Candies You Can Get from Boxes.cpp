class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        unordered_set<int> boxFound;
        for(auto &i : initialBoxes) {
            if(status[i]) q.push(i);
            else boxFound.insert(i);
        }
        int ans = 0;
       
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            ans += candies[top];
            for(auto &box : containedBoxes[top]) {
                if(status[box]) q.push(box);
                else boxFound.insert(box);
            }
            for(auto &key : keys[top]) {
                status[key] = 1;
                if(boxFound.count(key)) {
                    q.push(key);
                    boxFound.erase(key); /* Key can be present in duplicate, box can't */
                }
            }
        }
        return ans;
    }
};