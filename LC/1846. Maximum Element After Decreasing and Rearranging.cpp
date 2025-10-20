class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int prev = 0, n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i = 0; i<n; i++) prev = min(arr[i],prev + 1);
        return prev;
    }
};