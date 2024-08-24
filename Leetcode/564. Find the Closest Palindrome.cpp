class Solution {
private:
    long f(long firstHalf, bool isEven) {
        long ans = firstHalf;
        if(!isEven) {
            firstHalf /= 10;
        }
        while(firstHalf) {
            ans = (ans * 10) + (firstHalf % 10);
            firstHalf /= 10;
        }
        return ans;
    }
public:
    string nearestPalindromic(string s) {
        int n = s.length();
        long original = stol(s);
        bool isEven = !(n & 1);
        long firstHalf = stol(s.substr(0, n / 2 + (isEven ? 0 : 1)));
        vector<long> closest;
        closest.push_back(f(firstHalf, isEven));
        closest.push_back(f(firstHalf + 1, isEven));
        closest.push_back(f(firstHalf - 1, isEven));
        closest.push_back((long)pow(10, n) + 1);
        closest.push_back((long)pow(10, n - 1) - 1);
        int dif = INT_MAX;
        long ans = -1;
        for(auto &i : closest) {
            if(i != original) {
                long diff = abs(i - original);
                if(diff < dif) {
                    ans = i;
                    dif = diff;
                }
                else if(diff == dif) {
                    if(i < ans) ans = i;
                }
            }
        }
        return to_string(ans);
    }
};