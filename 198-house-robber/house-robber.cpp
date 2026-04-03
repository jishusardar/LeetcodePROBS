class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=0,curr=0;
        for(int i=n-1;i>=0;i--){
            int ans=max(nums[i]+prev,curr);
            prev=curr;
            curr=ans;

        }
        return curr;
    }
};