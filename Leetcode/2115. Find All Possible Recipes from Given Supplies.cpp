class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            int n = recipes.size();
            unordered_map<string, int> in;
            unordered_map<string, vector<string>> adj;
            for(int i = 0; i<ingredients.size(); i++) {
                for(auto &j : ingredients[i]) {
                    adj[j].push_back(recipes[i]);
                    in[recipes[i]]++;
                }
            }
            vector<string> ans;
            queue<string> q;
            for(auto &s : supplies) {
                q.push(s);
            }
            while(!q.empty()) {
                auto top = q.front();
                q.pop();
                for(auto &ng: adj[top]) {
                    in[ng]--;
                    if(!in[ng]) {
                        q.push(ng);
                        ans.push_back(ng);
                    }
                }
            }
            return ans;
        }
    };