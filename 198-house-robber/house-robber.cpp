class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int pre=0,last=0,curr=0;
        for(int i=n-1;i>=0;i--){
            curr=max(nums[i]+last,pre);
            last=pre;
            pre=curr;
        }
        return curr;
    }
};