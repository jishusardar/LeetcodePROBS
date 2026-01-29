class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0)
        return 0;
        else if(n==1)
        return 1;
        if(dp[n-1]==-1)
        dp[n-1]=solve(n-1,dp);
        if(dp[n-2]==-1)
        dp[n-2]=solve(n-2,dp);
        return dp[n-1]+dp[n-2];
    }
    int fib(int n) {
        vector<int>dp(n,-1);
        return solve(n,dp);
    }
};