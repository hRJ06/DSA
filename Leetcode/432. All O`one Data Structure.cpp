class AllOne {
private:
    unordered_map<string, int> mp;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        mp[key]++;
    }
    
    void dec(string key) {
        mp[key]--;
        if(!mp[key]) mp.erase(key);
    }
    
    string getMaxKey() {
        int cnt = 0;
        string ans = "";
        for(auto &i : mp) {
            if(i.second > cnt) {
                cnt = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
    
    string getMinKey() {
        int cnt = INT_MAX;
        string ans = "";
        for(auto &i : mp) {
            if(i.second < cnt) {
                cnt = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */