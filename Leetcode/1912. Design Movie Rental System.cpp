struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};

class MovieRentingSystem {
private:
    set<pair<int, pair<int, int>>> rented; /* {M, S, P} */
    unordered_map<int, set<pair<int, int>>> unrented; /* M -> [{P, S}] */
    unordered_map<pair<int, int>, int, pair_hash> movieShopToPrice; /* [M, S] -> P */
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &i : entries) {
            int shop = i[0], movie = i[1], price = i[2];
            unrented[movie].insert({price, shop});
            movieShopToPrice[{movie, shop}] = price; 
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        set<pair<int, int>> &s = unrented[movie];
        int count = min(5, (int)s.size());
        for(auto i=s.begin(); count > 0; i++, count--) {
            auto [price, shop] = *i;
            ans.push_back(shop);
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = movieShopToPrice[{movie, shop}];
        rented.insert({price, {shop, movie}});
        unrented[movie].erase({price, shop});
    }
    
    void drop(int shop, int movie) {
        int price = movieShopToPrice[{movie, shop}];
        rented.erase({price, {shop, movie}});
        unrented[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int count = min(5, (int)rented.size());
        for(auto i=rented.begin(); count > 0; i++, count--) {
            auto p = *i;
            ans.push_back({p.second.first, p.second.second});
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */