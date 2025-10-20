class Solution {
private:
    int f(string s, string t) {
        int hour1 = stoi(s.substr(0, 2));
        int min1 = stoi(s.substr(3, 2));
        int hour2 = stoi(t.substr(0, 2));
        int min2 = stoi(t.substr(3, 2));
        int dif = (hour2 - hour1) * 60 + (min2 - min1);
        if(dif < 0) dif += 24 * 60;  
        return dif;
    }
public:
    int findMinDifference(vector<string>& time) {
        int ans = INT_MAX, n = time.size();
        sort(time.begin(), time.end());
        for(int i = 1; i<n; i++) {
            ans = min(ans, f(time[i - 1], time[i]));
        }
        ans = min(ans, f(time[n  - 1], time[0]));
        return ans;
    }
};