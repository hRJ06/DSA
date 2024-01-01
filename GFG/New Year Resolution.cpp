//User function Template for C++

class Solution {
    private:
    bool f(int day,int total,int N,int coins[],vector<vector<int>> &dp) {
        if(total and (!(total % 20) or !(total % 24) or total == 2024)) return true;
        if(day >= N) return false;
        if(dp[day][total] != -1) return dp[day][total];
        int a = f(day + 1,total + coins[day],N,coins,dp);
        int b = f(day + 1,total,N,coins,dp);
        return dp[day][total] = a or b;
    }
    public:
    int isPossible(int N , int coins[]) 
    {   
        int total = 0;
        for(int i = 0; i<N; i++) total += coins[i];
        vector<vector<int>> dp(N,vector<int>(total + 1,-1));
        return f(0,0,N,coins,dp);
    }
    
};