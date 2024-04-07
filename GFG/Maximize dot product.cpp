class Solution{
	private:
	int f(int i,int j,int n,int m,int a[],int b[],vector<vector<int>> &dp) {
	    if(j >= m) return 0;
	    if(i >= n) return INT_MIN;
	    if(dp[i][j] != -1) return dp[i][j];
	    int nT = f(i + 1,j,n,m,a,b,dp);
	    int T = a[i] * b[j] + f(i + 1,j + 1,n,m,a,b,dp);
	    return dp[i][j] = max(nT,T);
	}
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
        vector<vector<int>> dp(n, vector<int>(m, -1));
	    return f(0,0,n,m,a,b,dp);
	} 
};