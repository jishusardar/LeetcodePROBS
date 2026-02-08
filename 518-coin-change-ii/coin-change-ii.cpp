class Solution {
public:
    int find(int index,int amount,int n,vector<int>&coins,vector<vector<int>>&dp){
        if(amount==0)
        return 1;
        if(index>=n||amount<0)
        return 0;
        if(dp[index][amount]!=-1)
        return dp[index][amount];
        return dp[index][amount]=find(index,amount-coins[index],n,coins,dp)+find(index+1,amount,n,coins,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return find(0,amount,n,coins,dp);
    }
};