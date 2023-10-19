
class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    queue<int> q;
	    vector<int> vis(V,0);
	    q.push(0);
	    int ans = 0;
	    while(!q.empty()) {
	        int n = q.size();
	        while(n--) {
	            int node = q.front();
	            vis[node] = 1;
	            q.pop();
	            if(node == X) return ans;
	            for(auto &i : adj[node]) if(!vis[i]) q.push(i);
	        }
	        ans++;
	    }
	    return -1;
	}
};