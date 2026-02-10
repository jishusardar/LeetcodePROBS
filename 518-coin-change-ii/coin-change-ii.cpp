class Solution {
public:
    int find(int n,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(amount==0)
        return 1;
        if(n<0)
        return 0;

        if(dp[n][amount]!=-1)
        return dp[n][amount];

        if(coins[n]>amount)
        return dp[n][amount]=find(n-1,amount,coins,dp);
        else
        return dp[n][amount]=find(n,amount-coins[n],coins,dp)+find(n-1,amount,coins,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return find(n-1,amount,coins,dp);
    }
};