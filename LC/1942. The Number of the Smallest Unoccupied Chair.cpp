typedef pair<int,int> p;
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int chairNo = 0; /* This is the by default chair i will allocate */
        int friendArrivalTime = times[targetFriend][0];
        sort(times.begin(), times.end());
        priority_queue<p, vector<p>, greater<p>> occupied; /* {departure, chairNo} */
        priority_queue<int, vector<int>, greater<int>> free; /* chairNo */
        for(auto &i : times) {
            int at = i[0];
            int dt = i[1];
            while(!occupied.empty() and occupied.top().first <= at) {
                free.push(occupied.top().second);
                occupied.pop();
            }
            if(free.empty()) {
                occupied.push({dt, chairNo});
                if(at == friendArrivalTime)
                    return chairNo;
                chairNo++;
            }
            else {
                int chair = free.top();
                free.pop();
                if(at == friendArrivalTime)
                    return chair;
                occupied.push({dt, chair});
            }
        }
        return -1;
    }
};