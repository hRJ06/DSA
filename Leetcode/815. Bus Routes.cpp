class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> bStopTobId;
        int n = routes.size();
        for(int i = 0; i<n; i++) {
            for(auto &j : routes[i])
                bStopTobId[j].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push({source,0});
        unordered_map<int,bool> bStop,busVis;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto top = q.front();
                q.pop();
                int curStop = top.first, busCount = top.second;
                if(curStop == target) return busCount;
                for(auto &bus: bStopTobId[curStop]) {
                    if(busVis[bus]) continue;
                    busVis[bus] = true;
                    for(auto &busStop : routes[bus]) {
                        if(!bStop[busStop]) {
                            bStop[busStop] = true;
                            q.push({busStop,busCount + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};