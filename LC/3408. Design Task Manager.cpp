class TaskManager {
private:
    struct Compare {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
            if(a.first != b.first) return a.first < b.first;
            return b.second < a.second;
        }
    };
    unordered_map<int, pair<int, int>> mp;
    set<pair<int, int>, Compare> s;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        s.insert({-priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority = mp[taskId].second;
        s.erase({-oldPriority, taskId});
        mp[taskId].second = newPriority;
        s.insert({-newPriority, taskId});
    }
    
    void rmv(int taskId) {
        int priority = mp[taskId].second;
        s.erase({-priority, taskId});
        mp.erase(taskId);
    }
    
    int execTop() {
        if(s.empty()) return -1;
        auto topTask = *s.begin();
        int taskId = topTask.second;
        int userId = mp[taskId].first;
        rmv(taskId);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */