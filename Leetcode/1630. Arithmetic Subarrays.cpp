
class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
    vector<bool> ans;
    int n = l.size();
    for(int i = 0; i<n; i++) {
      vector<int> v(nums.begin() + l[i], nums.begin() + 1 + r[i]);
      sort(v.begin(), v.end());
      if(v.size() <= 1) {
        ans.push_back(false);
        continue;
      }
      int diff = v[1] - v[0];
      bool f =  true;
      for(int j = 2; j<v.size(); j++)
        if(v[j] - v[j - 1] != diff) {
          f = false;
          break;
        }
      ans.push_back(f);
    }
    return ans;
  }
};
