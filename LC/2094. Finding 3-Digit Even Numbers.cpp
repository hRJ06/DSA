class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int d : digits) mp[d]++;
        for(int i = 100; i<=998; i += 2) {  
            int x = i;
            unordered_map<int, int> tmp = mp;
            bool valid = true;
            for(int j = 0; j<3; j++) {
                int d = x % 10;
                if(!tmp[d]) {
                    valid = false;
                    break;
                }
                tmp[d]--;
                x /= 10;
            }
            if(valid) ans.push_back(i);
        }
        return ans;
    }
};
