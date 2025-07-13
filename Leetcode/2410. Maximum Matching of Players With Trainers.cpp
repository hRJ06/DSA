class Solution {
private:
    bool f(int player, vector<int>& trainers, int &start, int &end) {
        int s = start, e = end;
        int ans = -1;
        while(s <= e) {
            int m = s + (e - s) / 2;
            if(trainers[m] >= player) {
                ans = m;
                e = m - 1;
            }
            else
                s = m + 1;
        }
        if(ans != -1) {
            start = ans + 1;
            return true;
        }
        return false;
    }
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));
        int ans = 0, s = 0, e = trainers.size() - 1;
        for(auto &i : players) {
            if(f(i, trainers, s, e)) 
                ans++;
        }   
        return ans;
    }
};