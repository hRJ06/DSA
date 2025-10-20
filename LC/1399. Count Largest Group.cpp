class Solution {
    private:
        int find(int n) {
            int sum = 0;
            while(n) {
                sum += (n % 10);
                n /= 10;
            }
            return sum;
        }
    public:
        int countLargestGroup(int n) {
           unordered_map<int, int> mp;
            for(int i = 1; i<=n; i++) {
                int digits = find(i);
                mp[digits]++;
            } 
            int ans = INT_MIN, count = 0;
            for(auto &i : mp) {
                if(i.second > ans) {
                    ans = i.second;
                    count = 1;
                }
                else if(i.second == ans) count++;
            }
            return count;
        }
    };