class Solution {
    private:
        bool check(vector<int> &candies,int m,long long k) {
            long long count = 0;
            for(auto &i : candies) {
                count += i / m;
                if(count >= k) return true;
            }
            return false;
        }
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int  s = 1, e = *max_element(candies.begin(),candies.end());
            int ans = 0; 
            while(s <= e) {
                int m = s + (e - s)/2;
                if(check(candies,m,k)) {
                    ans = m;
                    s = m + 1; 
                }
                else
                    e = m - 1;
            }
            return ans;
        }
    };