class Solution {
private:
    int f(vector<vector<int>> &items, int p) {
        int s = 0, e = items.size() - 1;
        int ans = 0;
        while(s <= e) {
            int m = s + (e - s) / 2;
            if(items[m][0] <= p) {
                ans = items[m][1];
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }
        return ans;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int beauty = INT_MIN;
        for(auto &i : items) {
            beauty = max(beauty, i[1]);
            i[1] = beauty;
        }
        vector<int> ans;
        for(auto &q : queries) {
            int price = q;
            int r = f(items, price);
            ans.push_back(r);
        }
        return ans;
    }
};