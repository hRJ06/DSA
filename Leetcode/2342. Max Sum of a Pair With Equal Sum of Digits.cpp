class Solution {
    private:
        int f(int i) {
            int sum = 0;
            while(i) {
                sum += (i % 10);
                i /= 10;
            }
            return sum;
        }
    public:
        int maximumSum(vector<int>& nums) {
            map<int, multiset<int, greater<int>>> mp;
            for(auto &i : nums) {
                int digSum = f(i);
                mp[digSum].insert(i);
            }
            int ans = -1;
            for(auto &i : mp) {
                if(i.second.size() >= 2) {
                    int total = *(i.second.begin());
                    i.second.erase(i.second.begin());
                    total += *(i.second.begin());
                    ans = max(ans, total);
                }
            }
            return ans;
        }
    };