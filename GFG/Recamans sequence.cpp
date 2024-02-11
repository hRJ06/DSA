class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        int prev = 0;
        unordered_set<int> s;
        vector<int> ans;
        s.insert(0);
        ans.push_back(0);
        for(int i = 1; i<n; i++) {
            int cur = prev - i;
            if(cur < 0 or s.find(cur) != s.end()) cur = prev + i;
            s.insert(cur);
            ans.push_back(cur);
            prev = cur;
        }
        return ans;
    }
};