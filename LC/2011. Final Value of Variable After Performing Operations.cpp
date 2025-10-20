class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(auto &i : operations) {
            if(i[0] != '+' and i[2] != '+') ans -= 1;
            else ans += 1;
        }
        return ans;
    }
};