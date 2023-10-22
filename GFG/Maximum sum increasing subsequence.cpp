class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> dp(n);
	    int ans = arr[0];
	    for(int i = 0; i<n; i++) dp[i] = arr[i];
	    for(int i = 1; i<n; i++) {
	        for(int j = 0; j<i; j++) 
	            if(arr[i] > arr[j]) 
	                if(arr[i] + dp[j] > dp[i]) dp[i] = arr[i] + dp[j];
	        ans = max(ans,dp[i]);
	    }
	    return ans;
	}  
};