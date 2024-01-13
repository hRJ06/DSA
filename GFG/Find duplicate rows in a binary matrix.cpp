class Solution
{   
public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        unordered_map<string, vector<int>> mp;
        for(int i = 0; i<M; i++) {
            string s = "";
            for(int j = 0; j<N; j++) {
                s += to_string(matrix[i][j]);
            }
            mp[s].push_back(i);
        }
        vector<int> ans;
        for(auto &i : mp) {
            if(i.second.size() > 1) {
                for(int j = 1; j<i.second.size(); j++) {
                    ans.push_back(i.second[j]);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    } 
};