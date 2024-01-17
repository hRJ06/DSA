class Solution {
    private:
        void f(vector<int> &arr,int n,set<vector<int>> &s,int index){
            if(index >= n){
                s.insert(arr);
                return;
            }
            for(int i = index; i<n; i++){
                swap(arr[index],arr[i]);
                f(arr,n,s,index + 1);
                swap(arr[index],arr[i]);
            }
        }
    public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>> s;
        f(arr,n,s,0);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};