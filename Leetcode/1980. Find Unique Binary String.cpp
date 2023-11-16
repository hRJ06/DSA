class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> s;
        for(auto &i : nums) 
            s.insert(bitset<16>(i).to_ulong());
        int n = pow(2,nums.size());
        for(int i = 0; i<n; i++) {
            if(s.find(i) == s.end()) {
                bitset<16> b(i);
                return b.to_string().substr(16 - nums.size());
            }
        }
        return "";
    }
};