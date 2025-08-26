class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0,end=0,sum=0,ans=INT_MAX;
        while(end<nums.size()){
            sum+=nums[end];
            while(sum>=target&&start<=end){
                ans=min(ans,end-start+1);
                sum-=nums[start];
                start++;
            }
            end++;
        }
        if(ans!=INT_MAX)
        return ans;
        return 0;
    }
};