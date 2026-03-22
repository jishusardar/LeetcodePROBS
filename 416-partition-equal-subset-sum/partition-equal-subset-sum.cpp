class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++)
        sum+=nums[i];
        if(sum%2)
        return 0;
        sum/=2;
        vector<int>dp(sum+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        for(int j=sum;j>=nums[i-1];j--)
        dp[j]=dp[j-nums[i-1]]||dp[j];
        return dp[sum];
    }
};