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
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2)));
        for(int i=0;i<=n;i++){
            for(int k=0;k<=1;k++){
                dp[i][0][k]=0;
            }
        }
        for(int i=0;i<=2;i++){
            for(int j=0;j<=1;j++){
                dp[n][i][j]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=2;j++){
                for(int k=1;k>=0;k--){
                    if(k){
                        dp[i][j][k]=max(-prices[i]+dp[i+1][j][k-1],dp[i+1][j][k]);
                    }
                    else{
                        dp[i][j][k]=max(prices[i]+dp[i+1][j-1][k+1],dp[i+1][j][k]);
                    }
                }
            }
        }
        return dp[0][2][1];
    }
};