class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        for(auto &i : tasks)
            v[i - 'A']++;
        sort(v.begin(),v.end());
        int chunk = v[25] - 1;
        int idle = chunk * n;
        for(int i = 24; i>=0; i--) 
            idle -= min(v[i],chunk);
        return idle < 0 ? tasks.size() : idle + tasks.size();
    }
};