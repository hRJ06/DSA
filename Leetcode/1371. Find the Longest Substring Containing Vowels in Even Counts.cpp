class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string,int> mp;
        vector<int> store(5, 0);
        mp["00000"] = -1;
        int ans = 0, n = s.length();
        for(int i = 0; i<n; i++) {
            switch (s[i]) {
                case 'a':
                    store[0] = (store[0] + 1) % 2;
                    break;
                case 'e':
                    store[1] = (store[1] + 1) % 2;
                    break;
                case 'i':
                    store[2] = (store[2] + 1) % 2;
                    break;
                case 'o':
                    store[3] = (store[3] + 1) % 2;
                    break;
                case 'u':
                    store[4] = (store[4] + 1) % 2;
                    break;
                default: 
                    break;
            }
            /* If 0110 -> 0110, it means characters between them have nullified each other effect, so even number of occurence */
            string key = "";
            for(int j = 0; j<5; j++)
                key += to_string(store[j]);
            if(mp.count(key))
                ans = max(ans, i - mp[key]);
            else
                mp[key] = i;
        }
        return ans;
    }
};