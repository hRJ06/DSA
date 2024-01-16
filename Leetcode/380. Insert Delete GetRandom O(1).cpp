class RandomizedSet {
private:
    unordered_map<int,int> mp;
    vector<int> store;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        store.push_back(val);
        mp[val] = store.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)) {
            int index = mp[val];
            int last = store.back();
            mp[last] = index;
            store[index] = last;
            store.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return store[rand() % store.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */