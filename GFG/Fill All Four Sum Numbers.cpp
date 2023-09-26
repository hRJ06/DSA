class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i = 0; i<n; i++) {
            if(i > 0 and arr[i] == arr[i - 1]) continue;
            for(int j = i + 1; j<n; j++) {
                if(j != (i + 1) and arr[j] == arr[j - 1]) continue;
                int k = j + 1;
                int l = n - 1;
                while(k < l) {
                    long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if(sum == target) {
                        ans.push_back({arr[i],arr[j],arr[k],arr[l]});
                        k++;
                        l--;
                        while(k < l and arr[k] == arr[k - 1]) k++;
                        while(k < l and arr[l] == arr[l + 1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                } 
            }
        }
        return ans;
    }
};