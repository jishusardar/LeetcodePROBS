class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans=INT_MIN;
        int sum=0;
        int sol=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sol+=nums[i]*i;
        }
        ans=max(ans,sol);
        int n=nums.size()-1;
        for(int i=nums.size()-1;i>0;i--){
            sol+=sum-nums[i];
            sol-=nums[i]*n;
            ans=max(ans,sol);
        }
        return ans;
    }
};