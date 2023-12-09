class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_map<int,int> mp;
        mp[0] = 0;
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += arr[i];
            if(mp.find(sum - 0) != mp.end()) return 1;
            mp[sum]++;
        }
        return 0;
    }
};