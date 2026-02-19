class Solution {
public:
    int find(int n,int m,string &s1,string &s2,vector<vector<int>>&dp){
        if(n==0||m==0)
        return 0;
        if(dp[n][m]!=-1)
        return dp[n][m];
        if(s1[n-1]==s2[m-1])
        return dp[n][m]=1+find(n-1,m-1,s1,s2,dp);
        else
        return dp[n][m]=max(find(n-1,m,s1,s2,dp),find(n,m-1,s1,s2,dp));
    }
    int minInsertions(string s) {
        int n=s.size();
        string s1=s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return n-find(n,n,s,s1,dp);
    }
};