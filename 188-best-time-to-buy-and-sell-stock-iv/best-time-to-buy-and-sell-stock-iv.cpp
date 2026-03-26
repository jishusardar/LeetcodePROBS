class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int total;
        vector<vector<int>>dp(k+1,vector<int>(n+1,0));
        for(int i=1;i<=k;i++){
            total=-prices[0];
            for(int j=2;j<=n;j++){
                dp[i][j]=max(dp[i][j-1],prices[j-1]+total);
                total=max(total,-prices[j-1]+dp[i-1][j]);
            }
        }
        return dp[k][n];
    }
};