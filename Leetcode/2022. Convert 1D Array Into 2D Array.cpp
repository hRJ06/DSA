class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        if(m * n != size) return {};
        vector<vector<int>> ans(m);
        int row = 0;
        for(int index = 0; index<size; index++) {
            if(index > 0 and !(index % n)) row++;
            ans[row].push_back(original[index]);
        }
        return ans;
    }
};