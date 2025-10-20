typedef long long ll;
class cmp {
    public:
        bool operator()(pair<ll,int> &a,pair<ll,int> &b) {
            if(a.first != b.first) return a.first > b.first;
            else return a.second > b.second;
        }
};
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        map<int,int> booked;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, cmp> occupiedRoom;
        priority_queue<int,vector<int>, greater<int>> freeRoom;
        for(int i = 0; i<n; i++)
            freeRoom.push(i);
        sort(meetings.begin(),meetings.end());
        for(auto &i : meetings) {
            ll start = i[0], end = i[1];
            while(!occupiedRoom.empty() and occupiedRoom.top().first <= start) {
                freeRoom.push(occupiedRoom.top().second);
                occupiedRoom.pop();
            }
            if(!freeRoom.empty()) {
                booked[freeRoom.top()]++;
                occupiedRoom.push({end,freeRoom.top()});
                freeRoom.pop();
            }
            else {
                auto top = occupiedRoom.top();
                occupiedRoom.pop();
                booked[top.second]++;
                occupiedRoom.push({top.first + end - start,top.second});
            }
        }
        int ans = -1, maxMeetings = 0;
        for(auto &i : booked) {
            if(i.second > maxMeetings) {
                ans = i.first;
                maxMeetings = i.second;
            }
        }
        return ans;
    }
};