class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> v;
        for(int i = 0; i<n; i++) {
            v.push_back({price[i],i + 1});
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(auto &i : v) {
            int total = i.first * i.second;
            if(total <= k) {
                ans += i.second;
                k -= total;
            }
            else {
                ans += (k / i.first);
                break;
            }
        }
        return ans;
    }
};