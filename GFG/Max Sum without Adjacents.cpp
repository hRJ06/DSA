//User function template for C++
class Solution{
private:
    int f(int i,int *arr,vector<int> &dp) {
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int a = arr[i] + f(i - 2,arr,dp);
        int b = f(i - 1,arr,dp);
        return dp[i] = max(a,b);
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	    return f(n - 1,arr,dp);
	}
};