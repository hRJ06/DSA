typedef pair<int, pair<int, int>> pi; /* {T, {S, D}} */
class Router {
private:
    int n;
    queue<pi> q;
    map<pi, bool> check; 
    unordered_map<int, vector<int>> dest;
public:
    Router(int memoryLimit) {
        n = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        pi el = {timestamp, {source, destination}};
        if(check.count(el)) return false;
        
        if(q.size() >= n) {
            pi p = q.front();
            q.pop();
            check.erase(p);
            int d = p.second.second;
            dest[d].erase(dest[d].begin());
        }
        q.push(el);
        check[el] = true;
        dest[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(!q.size()) return {};
        pi p = q.front();
        int d = p.second.second;
        dest[d].erase(dest[d].begin());
        check.erase(p);
        q.pop();
        return {p.second.first, p.second.second, p.first};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &v = dest[destination];
        if(!v.size()) return 0;
        auto l = lower_bound(v.begin(), v.end(), startTime);
        auto h = upper_bound(v.begin(), v.end(), endTime);
        return h - l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */