class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n,1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    temp[i]=max(temp[i],temp[j]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,temp[i]);
        }
        return ans;
    }
};