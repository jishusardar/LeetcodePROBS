class Solution {
public:
    int find(int trans,int buy,int index,int n,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(trans==0||index==n)
        return 0;
        if(dp[index][trans][buy]!=-1)
        return dp[index][trans][buy];
        if(buy){
            return dp[index][trans][buy]=max(-prices[index]+find(trans,0,index+1,n,prices,dp),find(trans,1,index+1,n,prices,dp));
        }
        else{
            return dp[index][trans][buy]=max(prices[index]+find(trans-1,1,index+1,n,prices,dp),find(trans,0,index+1,n,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return find(2,1,0,n,prices,dp);
    }
};