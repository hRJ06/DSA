const int MAX = 1e5 + 5;
bool prime[MAX];
int spf[MAX];
void sieve() {
    fill(prime, prime + MAX, true);
    for(int i = 1; i < MAX; i++)
        spf[i] = i;
    prime[0] = prime[1] = false;
    for(int i = 2; i * i<MAX; i++) {
        if(prime[i]) {
            for(int j = i * i; j<MAX; j += i) {
                if(prime[j])
                    spf[j] = i;
                prime[j] = false;
            }
        }
    }
}
vector<int> getFactorization2(int x) {
    vector<int> ret;
    unordered_map<int, int> factors;
    while (x != 1) {
        factors[spf[x]]++;
        x = x / spf[x];
    }
    for (auto factor : factors) ret.push_back(factor.first);
    return ret;
}
int count;
void depthFirstSearch(int node, unordered_map<int, vector<int>>& graph, vector<bool>& visited){
    if(visited[node])
        return;
    visited[node] = true;
    ::count++;
    for(auto neighbor : graph[node]){
        if(!visited[neighbor])
            depthFirstSearch(neighbor, graph, visited);
    }
}
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        sieve();       
        int n = nums.size();
        unordered_map<int, vector<int>> factorsMap;
        for(int i = 0; i<n; i++){
            factorsMap[i] = getFactorization2(nums[i]);
        }
        unordered_map<int, vector<int>> reversedFactorsMap;
        for(auto entry : factorsMap){
            int id = entry.first;
            for(auto factor : entry.second)
                reversedFactorsMap[factor].push_back(id);
        }
        unordered_map<int, vector<int>> graph;
        for(auto entry : reversedFactorsMap){
            vector<int> ids = entry.second;
            int idSize = ids.size();
            if(idSize <= 1)
                continue;   
            for(int i = 1; i<idSize; i++){
                int u = ids[i - 1];
                int v = ids[i];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        vector<bool> visited(n, false);
        ::count = 0;
        depthFirstSearch(0, graph, visited);
        if(::count != n)
            return false;
        return true; 
    }
};
