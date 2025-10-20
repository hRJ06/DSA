class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i = 0; i<n; i++) parent[i] = i;
    }
    int Find(int node){
        return parent[node] = (parent[node] == node) ? node : Find(parent[node]);
    }
    void Reset(int node){
        parent[node] = node;
    }
    void Union(int a, int b){
        int apar = Find(a), bpar = Find(b);
        if(apar != bpar){
            rank[apar] < rank[bpar] ? parent[apar] = bpar : parent[bpar] = apar;
            rank[apar] += rank[apar] == rank[bpar] ? 1 : 0;
        }
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),[&](vector<int> a,vector<int> b){return a[2] < b[2];});
        DSU dsu(n);
        dsu.Union(0, firstPerson);
        int m = meetings.size();
        for(int i = 0; i<m;) {
            int currentTime = meetings[i][2];
            vector<int> curPeople; // current peoples in the meeting
            while(i < m and meetings[i][2] == currentTime) {
                dsu.Union(meetings[i][0],meetings[i][1]); // connect each pair;
                curPeople.push_back(meetings[i][0]);
                curPeople.push_back(meetings[i][1]);
                i++;
            }
            for(auto &people : curPeople) {
                if(dsu.Find(people) != dsu.Find(0)) {
                    // Not a person containing secret now
                    // Break connection with pair
                    dsu.Reset(people);
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i<n; i++) {
            if(dsu.Find(i) == dsu.Find(0)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};