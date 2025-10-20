class Graph {
private:
    unordered_map<int,vector<pair<int,int>>> adj;
    int nodes;
    int dijkstra(int src,int dest) {
        int n = adj.size();
        vector<int> dist(nodes,INT_MAX);
        dist[src] = 0;
        set<pair<int,int>> s;
        s.insert({0,src});
        while(!s.empty()) {
            auto top = *(s.begin());
            int distance = top.first;
            int node = top.second;
            s.erase(s.begin());
            for(auto &ng : adj[node]) {
                if(distance + ng.second < dist[ng.first]) {
                    auto record = s.find({dist[ng.first],ng.first});
                    if(record != s.end())
                        s.erase(record);
                    dist[ng.first] = distance + ng.second;
                    s.insert({dist[ng.first],ng.first});
                }
            }
        }
        return dist[dest] != INT_MAX ? dist[dest] : -1;
    }
public:
    Graph(int n, vector<vector<int>>& edges) {
        nodes = n;
        for(auto &i : edges) 
            adj[i[0]].push_back({i[1],i[2]});
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1,node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */